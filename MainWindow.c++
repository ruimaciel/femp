#include "MainWindow.h++"
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QMdiSubWindow>

#include <string>
#include <fstream>
#include <iostream>	// for cout. remove after tests
#include <string>
#include <stdlib.h>	// getenv()

#include "NewProjectWizard.h++"
#include "fem_msh.h++"
#include "parsers/json.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	mdiArea = new QMdiArea;
	setCentralWidget(mdiArea);	// this main window has a Multiple Document Interface
	//mdiArea->setViewMode(QMdiArea::TabbedView);
	window_gl_viewport = NULL;	// no windows on startup

	// Load global options from the options files
	this->loadOptions();

	// initialize the member attributes
	this->hasUnsavedChanges = false;

	// set up the dock widgets
	/*
	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);
	*/

	// create actions and connect signals to slots
	this->createActions();
}


void MainWindow::newProject()
{
	// initialize a new project
	std::string default_path, tmp;

	default_path = getenv("HOME");
	if(options.getOption("project.new.default_directory",tmp, ""))
	{
		default_path += "/" + tmp;
	}

	/*
	Now the "new project" wizard will create a new project directory.
	Then it will call loadProject() to load the newly created project.
	*/
	NewProjectWizard np(this);
	connect(&np,SIGNAL(newProject(Document::Type)), this, SLOT(startNewProject(Document::Type)));
	np.exec();
}


void MainWindow::openProject()
{
	std::string last_path, tmp;

	// get the last dir where a project was opened 
	QFileDialog dialog(this);
	QStringList sl;

	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled, no file was loaded
		return;
	}
	// clear the document
	this->setUserInterfaceAsClosed();
	this->document.clear();

	// prepare the file
	sl = dialog.selectedFiles();
	document.file_name = new QString;
	*document.file_name = sl.at(0);

	// check if file exists
	QFile file;
	file.setFileName(*document.file_name);
	if(!file.exists())
	{
		QMessageBox::critical(this, tr("File not found"), tr("File was not found"));
		return;
	}

	//file exists, now open it and parse it
	if(file.open(QIODevice::ReadOnly|QIODevice::Text) == false)
	{
		QMessageBox::critical(this, tr("Error"), tr("There was an error opening the file"));
		return;
	}


	// read the file
	json_t *root = NULL;
	FILE *f = fdopen(file.handle(), "r");
	switch(json_stream_parse(f,&root) )
	{
		case JSON_OK:
			// all went well
			break;

		default:
			//TODO implement better error handling
			QMessageBox::critical(this, tr("Error"), tr("There was an error parsing the project file"));
			return;
			break;
	}
	#define PTEST(TEST) {if(!(TEST)){QMessageBox::critical(this, tr("Error"), tr("There was an error parsing the project file")); qWarning("PERROR line %d: " #TEST, __LINE__); return;} }
	#define PMOVE(TO)	{ PTEST(TO != NULL); cursor = TO; }

	// document in memory, now let the importing begin
	json_t *cursor = root;
	PTEST(cursor->child != NULL);

	cursor = cursor->child;
	PTEST(cursor->type == JSON_STRING);
	PTEST( QString::compare(cursor->text,"fem") == 0);
	//TODO finish this

	// move to the materials field
	PMOVE(cursor->next);	// pointing to root->materials
	PTEST( QString::compare(cursor->text,"materials") == 0);
	PMOVE(cursor->child);	// pointing to root->materials->array
	PTEST(cursor->type == JSON_ARRAY);
	if(cursor->child != NULL)	// root-"materials"->array should have items
	{
		// there are defined elements
		for(json_t *mc = cursor->child; mc != NULL; mc = mc->next)
		{
			fem::Material mat;
			QString temp;
			PTEST(mc->type == JSON_OBJECT);
			PTEST(mc->child != NULL);
			json_t *c = mc->child;
			PTEST(c->type == JSON_STRING);
			PTEST( QString::compare(c->text,"type") == 0);

			//set the material type
			PTEST( QString::compare(c->child->text,"linear elastic") == 0);
			mat.type = fem::Material::MAT_LINEAR_ELASTIC;

			// move to the label field
			PTEST(c->next != NULL);
			c = c->next;
			PTEST(c->type == JSON_STRING);
			PTEST( QString::compare(c->text,"label") == 0);
			mat.label = c->child->text;

			// move to the Young modulus field
			PTEST(c->next != NULL);
			c = c->next;
			PTEST(c->type == JSON_STRING);
			PTEST( QString::compare(c->text,"E") == 0);
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_NUMBER);
			temp = c->child->text;
			mat.E = temp.toDouble();

			// move to the Poisson coefficient field
			PTEST(c->next != NULL);
			c = c->next;
			PTEST(c->type == JSON_STRING);
			PTEST( QString::compare(c->text,"nu") == 0);
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_NUMBER);
			temp = c->child->text;
			mat.nu = temp.toDouble();

			// move to the elastic limit field
			PTEST(c->next != NULL);
			c = c->next;
			PTEST(c->type == JSON_STRING);
			PTEST( QString::compare(c->text,"fy") == 0);
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_NUMBER);
			temp = c->child->text;
			mat.fy = temp.toDouble();
			// end of field
			PTEST(c->next == NULL);

			document.model.material_list.push_back(mat);
		}
	}
	cursor = cursor->parent;	// point to root->"materials"

	// move to the nodes field
	PMOVE(cursor->next);	// pointing to root->nodes
	PTEST( QString::compare(cursor->text,"nodes") == 0);
	PMOVE(cursor->child);
	PTEST(cursor->type == JSON_ARRAY);
	if(cursor->child != NULL) // testing root->"nodes"->array for children
	{	// has child nodes
		QString temp;
		size_t n = 0;
		double p[3] = {0,0,0};
		json_t *ac = NULL;
		// iterate through the child nodes of "nodes":[]
		for(json_t *c = cursor->child; c != NULL; c = c->next)
		{
			ac = c;
			PTEST(ac->type == JSON_ARRAY);
			PTEST(ac->child != NULL);
			ac = ac->child;
			PTEST(ac->type == JSON_NUMBER);
			temp = ac->text;
			n = temp.toLongLong();	// get the node index

			PTEST(ac->next != NULL);
			ac = ac->next;	// move c to the coordinates array
			PTEST(ac->type == JSON_ARRAY);
			PTEST(ac->child != NULL);
			ac = ac->child;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[0] = temp.toDouble();	// get point.x()
			
			PTEST(ac->next != NULL);	// there must be a 2nd array element
			ac = ac->next;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[1] = temp.toDouble();	// get point.x()
			
			PTEST(ac->next != NULL);	// there must be a 2nd array element
			ac = ac->next;
			PTEST(ac->type == JSON_NUMBER);	// point to the first coordinate
			temp = ac->text;
			p[2] = temp.toDouble();	// get point.x()
			PTEST(ac->next == NULL);
			
			// having the values, let's add the node to the node list
			document.model.setNode(n, p[0], p[1], p[2]);
		}
	}
	cursor = cursor->parent;	// move to root->"nodes"

	// move to the elements field
	PMOVE(cursor->next);	// pointing to root->"elements"
	PTEST( QString::compare(cursor->text,"elements") == 0);
	PMOVE( cursor->child );	// pointing to root->"elements"->array
	PTEST( cursor->type == JSON_ARRAY);
	if(cursor->child != NULL)
	{	// elements present in this document
		size_t nn;	// number of nodes which will be expected for each type
		json_t *ec = NULL;
		fem::Element::Type type = fem::Element::FE_INVALID;

		for(json_t *c = cursor->child; c != NULL; c = c->next)
		{
			PTEST(c->type == JSON_OBJECT);
			PTEST(c->child != NULL);
			ec = c->child;	// pointing to root->"elements"->array->object->"type"
			PTEST(ec->type == JSON_STRING);
			PTEST(QString::compare(ec->text,"type") == 0);
			PTEST(ec->child->type == JSON_STRING);	// value of label "type" must be a string
			
			// identify this type and act accordingly
			switch(type = fem::Element::extractType(ec->child->text) )
			{
				case fem::Element::FE_LINE2:
					nn = 2;
					break;

				case fem::Element::FE_TRIANGLE3:
					nn = 3;
					break;

				case fem::Element::FE_QUADRANGLE4:
					nn = 4;
					break;

				case fem::Element::FE_TETRAHEDRON4:
					nn = 4;	// expect 4 nodes in the "nodes" array
					break;

				case fem::Element::FE_HEXAHEDRON8:
					nn = 8;
					break;

				case fem::Element::FE_PRISM6:
					nn = 6;
					break;

				case fem::Element::FE_PYRAMID5:
					nn = 5;
					break;

				case fem::Element::FE_LINE3:
					nn = 3;
					break;

				case fem::Element::FE_TRIANGLE6:
					nn = 6;
					break;

				case fem::Element::FE_QUADRANGLE9:
					nn = 9;
					break;

				case fem::Element::FE_TETRAHEDRON10:
					nn = 10;
					break;

				case fem::Element::FE_HEXAHEDRON27:
					nn = 27;
					break;

				case fem::Element::FE_PRISM18:
					nn = 18;
					break;

				case fem::Element::FE_PYRAMID14:
					nn = 14;
					break;

				case fem::Element::FE_QUADRANGLE8:
					nn = 8;
					break;

				case fem::Element::FE_HEXAHEDRON20:
					nn = 20;
					break;

				case fem::Element::FE_PRISM15:
					nn = 15;
					break;

				case fem::Element::FE_PYRAMID13:
					nn = 13;
					break;

				case fem::Element::FE_ITRIANGLE9:
					nn = 9;
					break;

				case fem::Element::FE_TRIANGLE10:
					nn = 10;
					break;

				case fem::Element::FE_ITRIANGLE12:
					nn = 12;
					break;

				case fem::Element::FE_TRIANGLE15:
					nn = 15;
					break;

				case fem::Element::FE_ITRIANGLE15:
					nn = 15;
					break;

				case fem::Element::FE_TRIANGLE21:
					nn = 21;
					break;

				case fem::Element::FE_EDGE4:
					nn = 4;
					break;

				case fem::Element::FE_EDGE5:
					nn = 5;
					break;

				case fem::Element::FE_EDGE6:
					nn = 6;
					break;

				case fem::Element::FE_TETRAHEDRON20:
					nn = 20;
					break;

				case fem::Element::FE_TETRAHEDRON35:
					nn = 35;
					break;

				case fem::Element::FE_TETRAHEDRON56:
					nn = 56;
					break;

				case fem::Element::FE_INVALID:
				default:
					qWarning("invalid element");
					continue;
					break;

			}
			// extract nodes
			PTEST(ec->next != NULL);
			ec = ec->next;
			PTEST(ec->type == JSON_STRING);
			PTEST(QString::compare(ec->text,"nodes") == 0);
			PTEST(ec->child != NULL);
			ec = ec->child;	// pointing to root->"elements"->array->object->"nodes"->array
			PTEST(ec->type == JSON_ARRAY);
			PTEST(ec->child != NULL);	// node array must be populated

			std::vector<size_t> tn;	// the temporary node vector
			QString temp;	// the temporary string, to convert numbers
			unsigned int i=0;
			for(json_t *eec = ec->child; eec != NULL; eec = eec->next, i++)	// pointing to root->"elements"->array->objects->"nodes"->array->number
			{
				PTEST(eec->type == JSON_NUMBER);
				temp = eec->text;
				tn.push_back(temp.toLongLong());
			}
			PTEST(tn.size() == nn);	// evaluate if the document had as many nodes as those which were expected

			// get this element's material
			if(ec->next != NULL)
			{	
				// there is still another field
				ec = ec->next;	// pointing to root->"elements"->array->object->"material"
				PTEST(ec->type == JSON_STRING);	// which must be a label
				PTEST(QString::compare(ec->text,"material") == 0);
				PTEST(ec->child != NULL);
				PTEST(ec->child->type == JSON_NUMBER);	// material must be a number
				temp = ec->child->text;
				document.model.setDefaultMaterial(temp.toLongLong());	// sets the material
			}
			// now let's add the element
			document.model.pushElement(type,tn); 
		}
	}
	cursor = cursor->parent;	// move to root->"elements"

	// move to the node restrictions field
	{
		// work the tree
		PMOVE(cursor->next);	// pointing to root->node restrictions
		PTEST( QString::compare(cursor->text,"node restrictions") == 0);
		PMOVE(cursor->child);	// pointing to root->node restrictions
		PTEST(cursor->type == JSON_ARRAY);

		if(cursor->child != NULL)	// node restrictions ahoy
		{
			// set the temporary variables
			fem::NodeRestrictions nr;
			QString temp;
			size_t node;
			json_t *c = NULL;	// temporary cursor

			// now let's cycle through all child objects associated with "node restrictions"
			for(json_t *nrc = cursor->child; nrc != NULL; nrc = nrc->next)
			{
				nr.reset();
				PTEST(nrc->type == JSON_OBJECT);
				PTEST(nrc->child != NULL);
				c = nrc->child;
				PTEST( QString::compare(c->text,"node") == 0);
				PTEST(c->child->type == JSON_NUMBER);
				temp = c->child->text;
				node = temp.toLongLong();	// get the target node number

				// get restrictions, one at a time until no other restriction is available
				if(c->next == NULL)	// no restrictions set. move on
					continue;	
				while( (c = c->next) != NULL)
				{
					PTEST(c->type == JSON_STRING);
					switch(fem::NodeRestrictions::extractType(c->text))
					{
						case fem::NodeRestrictions::NR_DX:
							nr.setdx();
							break;

						case fem::NodeRestrictions::NR_DY:
							nr.setdy();
							break;

						case fem::NodeRestrictions::NR_DZ:
							nr.setdz();
							break;

						default:
							PTEST(false);
							break;
					}
				}
				// now push the new Node REstrictions
				document.model.pushNodeRestrictions(node, nr);
			}
		}
		cursor = cursor->parent;
	}

	// move to the load patterns field
	{
		PMOVE(cursor->next);	// pointing to root->load patterns
		PTEST( QString::compare(cursor->text,"load patterns") == 0);
		PMOVE(cursor->child);
		PTEST(cursor->type == JSON_ARRAY);
		if(cursor->child != NULL)	// load patterns ahoy
		{
			json_t *c;
			fem::LoadPattern lp;	// temporary load pattern

			// cycle through the available load patterns
			for(json_t *lpc = cursor->child; lpc != NULL; lpc = lpc->next)
			{
				lp.clear();	// cleans the temporary load pattern object

				PTEST(lpc->type == JSON_OBJECT);
				PTEST(lpc->child != NULL);
				c = lpc->child;	// point to the first "node loads" entry, which must be "label"

				// get this load pattern's label
				PTEST(c->type == JSON_STRING);
				PTEST(QString::compare(c->text,"label") == 0);
				PTEST(c->child->type == JSON_STRING);
				lp.label = c->child->text;	// set the label
				PTEST(c->next != NULL);	// move to the following entry
				c = c->next;

				// get the "node loads"
				PTEST(c->type == JSON_STRING);
				if(QString::compare(c->text,"node loads") == 0)
				{
					// next item is a node load
					PTEST(c->child != NULL);
					PTEST(c->child->type == JSON_ARRAY);	// the "node loads" value must be a JSON_ARRAY
					if(c->child->child != NULL)	// node loads array is populated
					{
						json_t *nltc;	// node loads temporary cursor
						size_t n = 0;	// temporary node reference
						QString temp;	// temporary string for the number conversion
						fem::point force;	// temporary nodal load

						// extract all nodal loads
						for(json_t *nlc = c->child->child; nlc != NULL; nlc = nlc->next)
						{
							PTEST(nlc->type == JSON_OBJECT);
							PTEST(nlc->child != NULL);
							nltc = nlc->child;

							// extract the node reference
							PTEST(QString::compare(nltc->text,"node") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_NUMBER);
							temp = nltc->child->text;
							n = temp.toLongLong();	// and we have the node reference

							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(QString::compare(nltc->text,"force") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_ARRAY);
							PTEST(nltc->child->child != NULL);
							nltc = nltc->child->child;	// point node load temp cursor to the first item in the "force array"

							// extract the force components
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.x(temp.toDouble());	// force XX componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.y(temp.toDouble());	// force YY componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.z(temp.toDouble());	// force ZZ componet was obtained

							PTEST(nltc->next == NULL);
							// all info extracted
							lp.addNodalLoad(n, force);
						}
					}
					if(c->next == NULL)	// no more entries
						goto load_pattern_push;
					c = c->next;
					PTEST(c->type == JSON_STRING);
				}

				// get the "node displacements"
				if(QString::compare(c->text,"node displacements") == 0)
				{
					//TODO finish this
					PTEST(c->child != NULL);
					PTEST(c->child->type == JSON_ARRAY);	// the "node loads" value must be a JSON_ARRAY
					if(c->child->child != NULL)	// array is populated
					{
						//TODO this 
						json_t *nltc;	// node displacements temporary cursor
						size_t n = 0;	// temporary node reference
						QString temp;	// temporary string for the number conversion
						fem::point displacement;	// temporary nodal displacement

						// extract all nodal displacements
						for(json_t *nlc = c->child->child; nlc != NULL; nlc = nlc->next)
						{
							PTEST(nlc->type == JSON_OBJECT);
							PTEST(nlc->child != NULL);
							nltc = nlc->child;

							// extract the node reference
							PTEST(QString::compare(nltc->text,"node") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_NUMBER);
							temp = nltc->child->text;
							n = temp.toLongLong();	// and we have the node reference

							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(QString::compare(nltc->text,"displacement") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_ARRAY);
							PTEST(nltc->child->child != NULL);
							nltc = nltc->child->child;	// point node displacement temp cursor to the first item in the "displacement array"

							// extract the displacement components
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							displacement.x(temp.toDouble());	// displacement XX componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							displacement.y(temp.toDouble());	// displacement YY componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							displacement.z(temp.toDouble());	// displacement ZZ componet was obtained

							PTEST(nltc->next == NULL);
							// all info extracted
							lp.addNodalDisplacement(n, displacement);
						}
					}
					if(c->next == NULL)	// no more entries
						goto load_pattern_push;
					c = c->next;
					PTEST(c->type == JSON_STRING);
				}

				// get the "domain loads"
				if(QString::compare(c->text,"domain loads") == 0)
				{
					//TODO finish this
					PTEST(c->child != NULL);
					PTEST(c->child->type == JSON_ARRAY);	// the "node loads" value must be a JSON_ARRAY
					if(c->child->child != NULL)	// array is populated
					{
						//TODO this 
						json_t *nltc;	// domain forces temporary cursor
						size_t n = 0;	// temporary domain reference
						QString temp;	// temporary string for the number conversion
						fem::point force;	// temporary nodal force

						// extract all nodal forces
						for(json_t *nlc = c->child->child; nlc != NULL; nlc = nlc->next)
						{
							PTEST(nlc->type == JSON_OBJECT);
							PTEST(nlc->child != NULL);
							nltc = nlc->child;

							// extract the domain reference
							PTEST(QString::compare(nltc->text,"node") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_NUMBER);
							temp = nltc->child->text;
							n = temp.toLongLong();	// and we have the domain reference

							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(QString::compare(nltc->text,"force") == 0);
							PTEST(nltc->child != NULL);
							PTEST(nltc->child->type == JSON_ARRAY);
							PTEST(nltc->child->child != NULL);
							nltc = nltc->child->child;	// point domain force temp cursor to the first item in the "force array"

							// extract the force components
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.x(temp.toDouble());	// force XX componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.y(temp.toDouble());	// force YY componet was obtained
							PTEST(nltc->next != NULL);
							nltc = nltc->next;
							PTEST(nltc->type == JSON_NUMBER);
							temp = nltc->text;
							force.z(temp.toDouble());	// force ZZ componet was obtained

							PTEST(nltc->next == NULL);
							// all info extracted
							lp.addDomainLoad(n, force);
						}
					}
					if(c->next == NULL)	// no more entries
						goto load_pattern_push;
					c = c->next;
					PTEST(c->type == JSON_STRING);
				}

				// get the "surface loads"
				if(QString::compare(c->text,"surface loads") == 0)
				{
					//TODO finish this
					PTEST(c->child != NULL);
					PTEST(c->child->type == JSON_ARRAY);	// the "node loads" value must be a JSON_ARRAY
					if(c->child->child != NULL)	// array is populated
					{
					}
					if(c->next == NULL)	// no more entries
						goto load_pattern_push;
					c = c->next;
					PTEST(c->type == JSON_STRING);
				}

			load_pattern_push:	// nasty hack
				// push the newly prepared load pattern into the model stack
				document.model.pushLoadPattern(lp);
			}

		}

		//TODO finish this
		cursor = cursor->parent;
	}

	// move to the combinations field
	PMOVE(cursor->next);	// pointing to root->combinations
	PTEST( QString::compare(cursor->text,"combinations") == 0);
	//TODO finish this

	

	#undef PTEST
	// tweak the UI
	setUserInterfaceAsOpened();
}


void MainWindow::saveProject()
{
	//TODO finish this
	if(document.file_name == NULL)
	{
		QFileDialog dialog(this);
		QStringList sl;

		// setup the file dialog
		dialog.setFileMode(QFileDialog::AnyFile);
		dialog.setNameFilter(tr("FEM project (*.fem.json)"));
		dialog.setDefaultSuffix("fem.json");
		if(dialog.exec() == QDialog::Rejected)
		{
			// user cancelled 
			return;
		}
		sl = dialog.selectedFiles();
		document.file_name = new QString;
		*document.file_name = sl.at(0);
		// check if file already exists
		QFile file;
		file.setFileName(*document.file_name);
		if(file.exists())
		{
			QMessageBox msgBox;
			msgBox.setText(tr("File already exists") );
			msgBox.setInformativeText(tr("Do you want to overwrite it?") );
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if(msgBox.exec() == QMessageBox::No)
			{
				qWarning("rejected");
				delete document.file_name;
				document.file_name = NULL;
				return;
			}
				qWarning("accepted");
		}

		// set a new file name for this file
		
	}
	document.save();
	hasUnsavedChanges = false;
}


void MainWindow::saveProjectAs()
{
	qWarning("MainWindow::saveProjectAs() not yet implemented");
	//TODO finish this

	QFileDialog dialog(this);
	QStringList sl;

	// setup the file dialog
	dialog.setFileMode(QFileDialog::AnyFile);
	dialog.setNameFilter(tr("FEM project (*.fem.json)"));
	dialog.setDefaultSuffix("fem.json");
	if(dialog.exec() == QDialog::Rejected)
	{
		// user cancelled 
		return;
	}
	sl = dialog.selectedFiles();
	document.file_name = new QString;
	*document.file_name = sl.at(0);

	// tweak the UI
	document.save();
	hasUnsavedChanges = false;
}


void MainWindow::closeProject()
{
	if(this->hasUnsavedChanges)
	{
		// ask the user if he wants to save the changes
		QMessageBox msgBox;
		msgBox.setText("The document has been modified.");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		switch(msgBox.exec())
		{
			case QMessageBox::Save:
				this->saveProject();
				break;

			case QMessageBox::Discard:
				// move on
				break;

			case QMessageBox::Cancel:
				return;	// exit and do nothing
				break;

			default:
				// this part should never be reached
				break;
		}
	}

	// tweak the UI
	setUserInterfaceAsClosed();

	// free everything
	document.clear();

	//TODO finish this
}


void MainWindow::quit()
{
	if(this->hasUnsavedChanges)
	{
		// ask the user if he wants to save the changes
		QMessageBox msgBox;
		msgBox.setText("The document has been modified.");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		switch(msgBox.exec())
		{
			case QMessageBox::Save:
				this->saveProject();
				break;

			case QMessageBox::Discard:
				// move on
				break;

			case QMessageBox::Cancel:
				return;	// exit and do nothing
				break;

			default:
				// this part should never be reached
				break;
		}
	}

	// proceed to quit
	this->close();
}


void MainWindow::createActions()
{
	 connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newProject()));
	 connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openProject()));
	 connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveProject()));
	 connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(saveProjectAs()));
	 connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(closeProject()));
	 connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
	 connect(ui.actionImportMesh, SIGNAL(triggered()), this, SLOT(importMesh()));
}


void MainWindow::loadOptions()
{
	std::ifstream is;
	std::string path;

	// Set default options
	options.setDefault();
	options.setOption("viewport.node.radius",10.0f);	// sets the default node radius
	//TODO Set default options

	// Set system options
	options.setSystem();
	path = "/etc/femp/options.opt";
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		options.importFile(is);
		is.close();
	}

	// Set local options
	options.setLocal();
	path = getenv("HOME");
	path += "/.femp/options.opt";
	is.open(path.c_str(), std::ifstream::in);
	if(is.is_open())
	{
		options.importFile(is);
		is.close();
	}
}


/*
Imports a mesh from a mesh document 
*/
void MainWindow::importMesh()
{
	QStringList files;
	QFile mesh_file;
	QFileDialog dialog(this);
	
	// setup the file dialog
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Mesh files (*.msh)"));
	//TODO import options from ProgramOptions

	if(dialog.exec())
	{
		// import file
		files = dialog.selectedFiles();
		mesh_file.setFileName(files[0]);
		if(!mesh_file.open(QIODevice::ReadOnly | QIODevice::Text) )
		{	// failed to open file
			//TODO include file name
			qWarning("unable to open file %s",qPrintable(mesh_file.fileName()));
			QMessageBox msgBox(this);
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setWindowTitle("Error");
			msgBox.setText("Unable to open file "+mesh_file.fileName() );
			msgBox.setDefaultButton(QMessageBox::Ok);
			msgBox.exec();
			return;
		}

		// TODO import mesh from a Gmsh file
		FILE *f = fdopen(mesh_file.handle(), "r");
		fem_model_import_msh(f,document.model);
		mesh_file.close();
	}
	// now this document has unsaved changes
	hasUnsavedChanges = true;
}

	
void MainWindow::startNewProject(Document::Type type)
{
	// set the document settings 
	document.clear();
	document.setProjectType(type);

	// set the UI
	setUserInterfaceAsOpened();
	hasUnsavedChanges = false;
}


void MainWindow::setUserInterfaceAsOpened()	
{
	//TODO finish this
	// set the menus
	ui.menuProject->setEnabled(true);
	ui.menuView->setEnabled(true);
	ui.menuWindow->setEnabled(true);
	ui.actionSave->setEnabled(true);
	ui.actionSaveAs->setEnabled(true);
	ui.actionClose->setEnabled(true);

	// open all relevant MDI windows
	glWidget = new GLWidget(this);
	glWidget->setDocument(&document);
	double radius;
	options.getOption("viewport.node.radius",radius,20);
	glWidget->setNodeRadiusScale(radius);
	
	window_gl_viewport = new QMdiSubWindow(mdiArea);
	window_gl_viewport->setWidget(glWidget);
	window_gl_viewport->setAttribute(Qt::WA_DeleteOnClose);
	window_gl_viewport->setWindowTitle(tr("model viewport"));
	window_gl_viewport->showMaximized();
	//mdiArea->addSubWindow(window_gl_viewport);
	// enable the "close"
}


void MainWindow::setUserInterfaceAsClosed()	
{
	//TODO finish this
	// set the menus
	ui.menuProject->setDisabled(true);
	ui.menuView->setDisabled(true);
	ui.menuWindow->setDisabled(true);
	ui.actionSave->setDisabled(true);
	ui.actionSaveAs->setDisabled(true);
	ui.actionClose->setDisabled(true);

	// close all MDI windows
	if(window_gl_viewport != NULL)
	{
		mdiArea->removeSubWindow(window_gl_viewport);
		delete window_gl_viewport; 
		window_gl_viewport = NULL;
	}
	mdiArea->closeAllSubWindows();
}



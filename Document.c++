#include "Document.h++"

#include <QTextStream>

#include <stack>

#include "fem_msh.h++"
#include "parsers/json.h"


Document::Document()
{
    unsaved = false;
    file_name = NULL;
}


Document::Document(const Document & copied)
{
    this->unsaved = copied.unsaved;
    if (copied.file_name != NULL) {
	this->file_name = new QString;
	*this->file_name = *copied.file_name;
    }
    this->model = copied.model;
    this->document_type = copied.document_type;
}


Document::~Document()
{
    if (file_name != NULL)
	delete          file_name;
}


void
                Document::clear()
{
    unsaved = false;
    if (file_name != NULL) {
	delete file_name;
	file_name = NULL;
    }
    document_type = TYPE_NONE;
    model.clear();
}


enum Document::Error
Document::setFileName(QString new_file)
{
    if (this->file_name == NULL)
	this->file_name = new QString;
    *this->file_name = new_file;

    // check if file exists
    QFile           file;
    file.setFileName(*file_name);
    if (!file.exists()) {
	delete(this->file_name);
	this->file_name = NULL;
	return ERR_FILE_NOT_FOUND;
    }
    // TODO perform checks on the file_name

    return ERR_OK;
}


enum Document:: Error
Document::load()
{
    QFile           file;
    // TODO check if path exists
    if (file_name == NULL)
	return ERR_FILE_NOT_FOUND;

    file.setFileName(*file_name);
    if (!file.exists())
	return ERR_FILE_NOT_FOUND;

    // sets up all variables
    model.clear();

    // load the project files
    // file exists, now open it and parse it
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false) {
	return ERR_FILE_OPEN;
    }
    // read the file
    json_t         *root = NULL;
    FILE           *f = fdopen(file.handle(), "r");
    switch (json_stream_parse(f, &root)) {
    case JSON_OK:
	// all went well
	break;

    default:
	return ERR_PARSER_ERROR;
	break;
    }

    // JSON document successfully parsed. Now let's extract stuff from it
#define PTEST(TEST) {if(!(TEST)){qWarning("PERROR line %d: " #TEST, __LINE__); return ERR_PARSER_ERROR;} }
#define PMOVE(TO)	{ PTEST(TO != NULL); cursor = TO; }
#define PMOVE_TYPE(CURSOR,TO,TYPE)	{ PTEST(TO != NULL); PTEST(TO->type != TYPE); CURSOR = TO; }
#define PMOVE_TOCHILD(CURSOR)	{ PTEST(CURSOR->child != NULL); CURSOR = CURSOR->child;}
#define PMOVE_TOCHILD_TYPE(CURSOR,TYPE)	{ PTEST(CURSOR->child != NULL); CURSOR = CURSOR->child; PTEST(CURSOR->type == TYPE);}
#define PMOVE_TONEXT(CURSOR)	{ PTEST(CURSOR->next != NULL); CURSOR = CURSOR->next;}
#define PMOVE_TONEXT_TYPE(CURSOR,TYPE)	{ PTEST(CURSOR->next != NULL); CURSOR = CURSOR->next; PTEST(CURSOR->type == TYPE);}
#define PMOVE_DOWN(CURSOR)	{ PTEST(CURSOR->parent != NULL); CURSOR = CURSOR->parent;}

    // document in memory, now let the importing begin
    json_t         *cursor = root;

    PMOVE_TOCHILD(cursor);

    PTEST(cursor->type == JSON_STRING);
    PTEST(QString::compare(cursor->text, "fem") == 0);
    // TODO finish this

    // move to the materials field
    PMOVE(cursor->next);	// pointing to root->materials
    PTEST(QString::compare(cursor->text, "materials") == 0);
    PMOVE_TOCHILD_TYPE(cursor, JSON_ARRAY);
    if (cursor->child != NULL)	// root-"materials"->array should have
	// items
    {
	// there are defined elements
	for (json_t * mc = cursor->child; mc != NULL; mc = mc->next) {
	    fem::Material mat;
	    QString         temp;
	    PTEST(mc->type == JSON_OBJECT);
	    PTEST(mc->child != NULL);
	    json_t         *c = mc->child;	// switched cursor
	    PTEST(c->type == JSON_STRING);
	    PTEST(QString::compare(c->text, "type") == 0);

	    // set the material type
	    PTEST(QString::compare(c->child->text, "linear elastic") == 0);
	    mat.type = fem::Material::MAT_LINEAR_ELASTIC;

	    // move to the label field
	    PMOVE_TONEXT_TYPE(c, JSON_STRING);
	    PTEST(QString::compare(c->text, "label") == 0);
	    mat.label = c->child->text;

	    // move to the Young modulus field
	    PMOVE_TONEXT_TYPE(c, JSON_STRING);
	    PTEST(QString::compare(c->text, "E") == 0);
	    PTEST(c->child != NULL);
	    PTEST(c->child->type == JSON_NUMBER);
	    temp = c->child->text;
	    mat.E = temp.toDouble();

	    // move to the Poisson coefficient field
	    PTEST(c->next != NULL);
	    c = c->next;
	    PTEST(c->type == JSON_STRING);
	    PTEST(QString::compare(c->text, "nu") == 0);
	    PTEST(c->child != NULL);
	    PTEST(c->child->type == JSON_NUMBER);
	    temp = c->child->text;
	    mat.nu = temp.toDouble();

	    // move to the elastic limit field
	    PTEST(c->next != NULL);
	    c = c->next;
	    PTEST(c->type == JSON_STRING);
	    PTEST(QString::compare(c->text, "fy") == 0);
	    PTEST(c->child != NULL);
	    PTEST(c->child->type == JSON_NUMBER);
	    temp = c->child->text;
	    mat.fy = temp.toDouble();
	    // end of field
	    PTEST(c->next == NULL);

	    model.material_list.push_back(mat);
	}
    }
    cursor = cursor->parent;	// point to root->"materials"

    // move to the nodes field
    PMOVE(cursor->next);	// pointing to root->nodes
    PTEST(QString::compare(cursor->text, "nodes") == 0);
    PMOVE(cursor->child);
    PTEST(cursor->type == JSON_ARRAY);
    if (cursor->child != NULL)	// testing root->"nodes"->array for
	// children
    {				// has child nodes
	QString         temp;
	size_t          n = 0;
	double          p[3] = { 0, 0, 0 };
	json_t         *ac = NULL;
	// iterate through the child nodes of "nodes":[]
	for (json_t * c = cursor->child; c != NULL; c = c->next) {
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
	    PTEST(ac->type == JSON_NUMBER);	// point to the first
	    // coordinate
	    temp = ac->text;
	    p[0] = temp.toDouble();	// get point.x()

	    PTEST(ac->next != NULL);	// there must be a 2nd array
	    // element
	    ac = ac->next;
	    PTEST(ac->type == JSON_NUMBER);	// point to the first
	    // coordinate
	    temp = ac->text;
	    p[1] = temp.toDouble();	// get point.x()

	    PTEST(ac->next != NULL);	// there must be a 2nd array
	    // element
	    ac = ac->next;
	    PTEST(ac->type == JSON_NUMBER);	// point to the first
	    // coordinate
	    temp = ac->text;
	    p[2] = temp.toDouble();	// get point.x()
	    PTEST(ac->next == NULL);

	    // having the values, let's add the node to the node list
	    model.setNode(n, p[0], p[1], p[2]);
	}
    }
    cursor = cursor->parent;	// move to root->"nodes"

    // move to the elements field
    PMOVE(cursor->next);	// pointing to root->"elements"
    PTEST(QString::compare(cursor->text, "elements") == 0);
    PMOVE(cursor->child);	// pointing to root->"elements"->array
    PTEST(cursor->type == JSON_ARRAY);
    if (cursor->child != NULL) {	// elements present in this
	// document
	size_t          nn;	// number of nodes which will be expected
	// for each type
	json_t         *ec = NULL;
	fem::Element::Type type = fem::Element::FE_INVALID;

	for (json_t * c = cursor->child; c != NULL; c = c->next) {
	    PTEST(c->type == JSON_OBJECT);
	    PTEST(c->child != NULL);
	    ec = c->child;	// pointing to
	    // root->"elements"->array->object->"type"
	    PTEST(ec->type == JSON_STRING);
	    PTEST(QString::compare(ec->text, "type") == 0);
	    PTEST(ec->child->type == JSON_STRING);	// value of label
	    // "type" must be
	    // a string

	    // identify this type and act accordingly
	    switch (type = fem::Element::extractType(ec->child->text)) {
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
		nn = 4;		// expect 4 nodes in the "nodes" array
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
	    PTEST(QString::compare(ec->text, "nodes") == 0);
	    PTEST(ec->child != NULL);
	    ec = ec->child;	// pointing to
	    // root->"elements"->array->object->"nodes"->array
	    PTEST(ec->type == JSON_ARRAY);
	    PTEST(ec->child != NULL);	// node array must be populated

	    std::vector < size_t > tn;	// the temporary node vector
	    QString         temp;	// the temporary string, to
	    // convert numbers
	    unsigned int    i = 0;
	    for (json_t * eec = ec->child; eec != NULL; eec = eec->next, i++)	// pointing 
										// 
		// to 
		// root->"elements"->array->objects->"nodes"->array->number
	    {
		PTEST(eec->type == JSON_NUMBER);
		temp = eec->text;
		tn.push_back(temp.toLongLong());
	    }
	    PTEST(tn.size() == nn);	// evaluate if the document had as 
					// 
	    // many nodes as those which were
	    // expected

	    // get this element's material
	    if (ec->next != NULL) {
		// there is still another field
		ec = ec->next;	// pointing to
		// root->"elements"->array->object->"material"
		PTEST(ec->type == JSON_STRING);	// which must be a label
		PTEST(QString::compare(ec->text, "material") == 0);
		PTEST(ec->child != NULL);
		PTEST(ec->child->type == JSON_NUMBER);	// material must
		// be a number
		temp = ec->child->text;
		model.setDefaultMaterial(temp.toLongLong());	// sets
		// the
		// material
	    }
	    // now let's add the element
	    model.pushElement(type, tn);
	}
    }
    cursor = cursor->parent;	// move to root->"elements"

    // move to the node restrictions field
    {
	// work the tree
	PMOVE(cursor->next);	// pointing to root->node restrictions
	PTEST(QString::compare(cursor->text, "node restrictions") == 0);
	PMOVE(cursor->child);	// pointing to root->node restrictions
	PTEST(cursor->type == JSON_ARRAY);

	if (cursor->child != NULL)	// node restrictions ahoy
	{
	    // set the temporary variables
	    fem::NodeRestrictions nr;
	    QString         temp;
	    size_t          node;
	    json_t         *c = NULL;	// temporary cursor

	    // now let's cycle through all child objects associated with
	    // "node restrictions"
	    for (json_t * nrc = cursor->child; nrc != NULL;
		 nrc = nrc->next) {
		nr.reset();
		PTEST(nrc->type == JSON_OBJECT);
		PTEST(nrc->child != NULL);
		c = nrc->child;
		PTEST(QString::compare(c->text, "node") == 0);
		PTEST(c->child->type == JSON_NUMBER);
		temp = c->child->text;
		node = temp.toLongLong();	// get the target node
		// number

		// get restrictions, one at a time until no other
		// restriction is available
		if (c->next == NULL)	// no restrictions set. move on
		    continue;
		while ((c = c->next) != NULL) {
		    PTEST(c->type == JSON_STRING);
		    switch (fem::NodeRestrictions::extractType(c->text)) {
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
		model.pushNodeRestrictions(node, nr);
	    }
	}
	cursor = cursor->parent;
    }

    // move to the load patterns field
    {
	PMOVE(cursor->next);	// pointing to root->load patterns
	PTEST(QString::compare(cursor->text, "load patterns") == 0);
	PMOVE(cursor->child);
	PTEST(cursor->type == JSON_ARRAY);
	if (cursor->child != NULL)	// load patterns ahoy
	{
	    json_t         *c;
	    fem::LoadPattern lp;	// temporary load pattern

	    // cycle through the available load patterns
	    for (json_t * lpc = cursor->child; lpc != NULL;
		 lpc = lpc->next) {
		lp.clear();	// cleans the temporary load pattern
		// object

		PTEST(lpc->type == JSON_OBJECT);
		PTEST(lpc->child != NULL);
		c = lpc->child;	// point to the first "nodal loads" entry, 
				// 
		// which must be "label"

		// get this load pattern's label
		PTEST(c->type == JSON_STRING);
		PTEST(QString::compare(c->text, "label") == 0);
		PTEST(c->child->type == JSON_STRING);
		lp.label = c->child->text;	// set the label

		if (c->next != NULL)	// this load pattern has declared
		    // forces
		{
		    c = c->next;	// move to the next field

		    // get the "nodal loads"
		    PTEST(c->type == JSON_STRING);
		    if (QString::compare(c->text, "nodal loads") == 0) {
			// next item is a node load
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_ARRAY);	// the
			// "nodal
			// loads"
			// value
			// must be 
			// a
			// JSON_ARRAY
			if (c->child->child != NULL)	// nodal loads
			    // array is
			    // populated
			{
			    json_t         *nltc;	// nodal loads
			    // temporary
			    // cursor
			    size_t          n = 0;	// temporary node
			    // reference
			    QString         temp;	// temporary
			    // string for the
			    // number
			    // conversion
			    fem::point force;	// temporary nodal load

			    // extract all nodal loads
			    for (json_t * nlc = c->child->child;
				 nlc != NULL; nlc = nlc->next) {
				PTEST(nlc->type == JSON_OBJECT);
				PTEST(nlc->child != NULL);
				nltc = nlc->child;

				// extract the node reference
				PTEST(QString::compare(nltc->text, "node")
				      == 0);
				PTEST(nltc->child != NULL);
				PTEST(nltc->child->type == JSON_NUMBER);
				temp = nltc->child->text;
				n = temp.toLongLong();	// and we have the 
							// 
				// node reference

				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(QString::compare(nltc->text, "force")
				      == 0);
				PTEST(nltc->child != NULL);
				PTEST(nltc->child->type == JSON_ARRAY);
				PTEST(nltc->child->child != NULL);
				nltc = nltc->child->child;	// point
				// node
				// load
				// temp
				// cursor
				// to the
				// first
				// item in 
				// the
				// "force
				// array"

				// extract the force components
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				force.x(temp.toDouble());	// force
				// XX
				// componet 
				// was
				// obtained
				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				force.y(temp.toDouble());	// force
				// YY
				// componet 
				// was
				// obtained
				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				force.z(temp.toDouble());	// force
				// ZZ
				// componet 
				// was
				// obtained

				PTEST(nltc->next == NULL);
				// all info extracted
				lp.addNodalLoad(n, force);
			    }
			}
			if (c->next == NULL)	// no more entries
			    goto load_pattern_push;
			c = c->next;
			PTEST(c->type == JSON_STRING);
		    }
		    // get the "node displacements"
		    if (QString::compare(c->text, "node displacements") ==
			0) {
			// TODO finish this
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_ARRAY);	// the
			// "nodal
			// loads"
			// value
			// must be 
			// a
			// JSON_ARRAY
			if (c->child->child != NULL)	// array is
			    // populated
			{
			    // TODO this 
			    json_t         *nltc;	// node
			    // displacements
			    // temporary
			    // cursor
			    size_t          n = 0;	// temporary node
			    // reference
			    QString         temp;	// temporary
			    // string for the
			    // number
			    // conversion
			    fem::point displacement;	// temporary nodal 
							// 
			    // displacement

			    // extract all nodal displacements
			    for (json_t * nlc = c->child->child;
				 nlc != NULL; nlc = nlc->next) {
				PTEST(nlc->type == JSON_OBJECT);
				PTEST(nlc->child != NULL);
				nltc = nlc->child;

				// extract the node reference
				PTEST(QString::compare(nltc->text, "node")
				      == 0);
				PTEST(nltc->child != NULL);
				PTEST(nltc->child->type == JSON_NUMBER);
				temp = nltc->child->text;
				n = temp.toLongLong();	// and we have the 
							// 
				// node reference

				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(QString::compare
				      (nltc->text, "displacement") == 0);
				PTEST(nltc->child != NULL);
				PTEST(nltc->child->type == JSON_ARRAY);
				PTEST(nltc->child->child != NULL);
				nltc = nltc->child->child;	// point
				// node
				// displacement 
				// temp
				// cursor
				// to the
				// first
				// item in 
				// the
				// "displacement 
				// array"

				// extract the displacement components
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				displacement.x(temp.toDouble());	// displacement 
									// 
				// XX 
				// componet 
				// was 
				// obtained
				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				displacement.y(temp.toDouble());	// displacement 
									// 
				// YY 
				// componet 
				// was 
				// obtained
				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(nltc->type == JSON_NUMBER);
				temp = nltc->text;
				displacement.z(temp.toDouble());	// displacement 
									// 
				// ZZ 
				// componet 
				// was 
				// obtained

				PTEST(nltc->next == NULL);
				// all info extracted
				lp.addNodalDisplacement(n, displacement);
			    }
			}
			if (c->next == NULL)	// no more entries
			    goto load_pattern_push;
			c = c->next;
			PTEST(c->type == JSON_STRING);
		    }
		    // get the "domain loads"
		    if (QString::compare(c->text, "domain loads") == 0) {
			// TODO finish this
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_ARRAY);	// the
			// "nodal
			// loads"
			// value
			// must be 
			// a
			// JSON_ARRAY
			if (c->child->child != NULL)	// array is
			    // populated
			{
			    // TODO this 
			    json_t         *nltc;	// domain forces
			    // temporary
			    // cursor
			    size_t          n = 0;	// temporary
			    // element
			    // reference
			    QString         temp;	// temporary
			    // string for the
			    // number
			    // conversion
			    fem::point force;	// temporary nodal force

			    // extract all domain load definitions
			    for (json_t * nlc = c->child->child;
				 nlc != NULL; nlc = nlc->next) {
				// TODO redefine this entire part
				PTEST(nlc->type == JSON_OBJECT);
				PTEST(nlc->child != NULL);
				nltc = nlc->child;

				// extract the domain reference
				PTEST(QString::compare
				      (nltc->text, "element") == 0);
				PTEST(nltc->child != NULL);
				PTEST(nltc->child->type == JSON_NUMBER);
				temp = nltc->child->text;
				n = temp.toLongLong();	// and we have the 
							// 
				// element
				// reference

				/*
				 * // extract the number of expected nodes 
				 * for this particular element type size_t 
				 * nodes; // to store the expected number
				 * of nodes
				 * switch(model.element_list[n].type) {
				 * case fem::Element::FE_LINE2: nodes =
				 * 2; break;
				 * 
				 * case fem::Element::FE_TRIANGLE3: nodes 
				 * = 3; break;
				 * 
				 * case fem::Element::FE_QUADRANGLE4:
				 * nodes = 4; break;
				 * 
				 * case fem::Element::FE_TETRAHEDRON4:
				 * nodes = 4; break;
				 * 
				 * case fem::Element::FE_HEXAHEDRON8:
				 * nodes = 8; break;
				 * 
				 * case fem::Element::FE_PRISM6: nodes =
				 * 6; break;
				 * 
				 * case fem::Element::FE_PYRAMID5: nodes
				 * = 5; break;
				 * 
				 * case fem::Element::FE_LINE3: nodes =
				 * 3; break;
				 * 
				 * case fem::Element::FE_TRIANGLE6: nodes 
				 * = 6; break;
				 * 
				 * case fem::Element::FE_QUADRANGLE9:
				 * nodes = 9; break;
				 * 
				 * case fem::Element::FE_TETRAHEDRON10:
				 * nodes = 10; break;
				 * 
				 * case fem::Element::FE_HEXAHEDRON27:
				 * nodes = 27; break;
				 * 
				 * case fem::Element::FE_PRISM18: nodes = 
				 * 18; break;
				 * 
				 * case fem::Element::FE_PYRAMID14: nodes 
				 * = 14; break;
				 * 
				 * case fem::Element::FE_QUADRANGLE8:
				 * nodes = 8; break;
				 * 
				 * case fem::Element::FE_HEXAHEDRON20:
				 * nodes = 20; break;
				 * 
				 * case fem::Element::FE_PRISM15: nodes = 
				 * 15; break;
				 * 
				 * case fem::Element::FE_PYRAMID13: nodes 
				 * = 13; break;
				 * 
				 * case fem::Element::FE_ITRIANGLE9:
				 * nodes = 9; break;
				 * 
				 * case fem::Element::FE_TRIANGLE10:
				 * nodes = 10; break;
				 * 
				 * case fem::Element::FE_ITRIANGLE12:
				 * nodes = 12; break;
				 * 
				 * case fem::Element::FE_TRIANGLE15:
				 * nodes = 15; break;
				 * 
				 * case fem::Element::FE_ITRIANGLE15:
				 * nodes = 15; break;
				 * 
				 * case fem::Element::FE_TRIANGLE21:
				 * nodes = 21; break;
				 * 
				 * case fem::Element::FE_EDGE4: nodes =
				 * 4; break;
				 * 
				 * case fem::Element::FE_EDGE5: nodes =
				 * 5; break;
				 * 
				 * case fem::Element::FE_EDGE6: nodes =
				 * 6; break;
				 * 
				 * case fem::Element::FE_TETRAHEDRON20:
				 * nodes = 20; break;
				 * 
				 * case fem::Element::FE_TETRAHEDRON35:
				 * nodes = 35; break;
				 * 
				 * case fem::Element::FE_TETRAHEDRON56:
				 * nodes = 56; break;
				 * 
				 * default: qWarning("unknown element
				 * type"); return ERR_PARSER_ERROR; //TODO 
				 * return to sane point break; } 
				 */

				PTEST(nltc->next != NULL);
				nltc = nltc->next;
				PTEST(QString::compare(nltc->text, "force")
				      == 0);
				PMOVE_TOCHILD_TYPE(nltc, JSON_ARRAY);

				// now cycle through all force vectors

				// extract the force components
				PMOVE_TOCHILD_TYPE(nltc, JSON_NUMBER);
				temp = nltc->text;
				force.x(temp.toDouble());	// force
				// XX
				// component 
				// was
				// obtained
				PMOVE_TONEXT_TYPE(nltc, JSON_NUMBER);
				temp = nltc->text;
				force.y(temp.toDouble());	// force
				// YY
				// componet 
				// was
				// obtained
				PMOVE_TONEXT_TYPE(nltc, JSON_NUMBER);
				temp = nltc->text;
				force.z(temp.toDouble());	// force
				// ZZ
				// componet 
				// was
				// obtained

				PTEST(nltc->next == NULL);

				// all info extracted
				lp.addDomainLoad(n, force);
			    }
			}
			if (c->next == NULL)	// no more entries
			    goto load_pattern_push;
			c = c->next;
			PTEST(c->type == JSON_STRING);
		    }
		    // get the "surface loads"
		    if (QString::compare(c->text, "surface loads") == 0) {
			// TODO finish this
			PTEST(c->child != NULL);
			PTEST(c->child->type == JSON_ARRAY);	// the
			// "nodal
			// loads"
			// value
			// must be 
			// a
			// JSON_ARRAY
			if (c->child->child != NULL)	// array is
			    // populated
			{
			    // TODO implement surface loads
			}
			if (c->next == NULL)	// no more entries
			    goto load_pattern_push;
			c = c->next;
			PTEST(c->type == JSON_STRING);
		    }
		}

	      load_pattern_push:	// nasty hack
		// push the newly prepared load pattern into the model
		// stack
		model.pushLoadPattern(lp);
	    }

	}
	// TODO finish this
	cursor = cursor->parent;
    }

    // move to the combinations field
    PMOVE(cursor->next);	// pointing to root->combinations
    PTEST(QString::compare(cursor->text, "combinations") == 0);

    // TODO finish this
#undef PTEST

    unsaved = false;
    return ERR_OK;
}


enum Document::Error Document::load2()
{
	QFile           file;
	// TODO check if path exists
	if (file_name == NULL)
		return ERR_FILE_NOT_FOUND;

	file.setFileName(*file_name);
	if (!file.exists())
		return ERR_FILE_NOT_FOUND;

	// sets up all variables
	model.clear();

	// load the project files
	// file exists, now open it and parse it
	if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false) {
		return ERR_FILE_OPEN;
	}
	// read the file
	json_t         *root = NULL;
	FILE           *f = fdopen(file.handle(), "r");
	switch (json_stream_parse(f, &root)) {
		case JSON_OK:
			// all went well
			break;

		default:
			return ERR_PARSER_ERROR;
			break;
	}

	// JSON document successfully parsed. Now let's extract stuff from it
	std::stack < json_t * >cursor;
	std::stack < int >state;	// the parser's states

	// temporary variables used to build the document
	fem::Material material;
	size_t          ref;
	std::vector < size_t > refs;
	fem::Element element;
	fem::NodeRestrictions node_restrictions;
	fem::LoadPattern load_pattern;
	QString         text;
	fem::point v;

	// initializing the parser
	cursor.push(root);
	state.push(0);		// starting state

#define ERROR()	{std::cout << "State " << state.top() << std::endl; goto error;}
#define CURSOR_PUSH(TYPE) { if(cursor.top()->child == NULL) ERROR(); if (cursor.top()->child->type != TYPE) ERROR(); cursor.push(cursor.top()->child);}
#define CURSOR_VERIFY_TEXT(TEXT)	{if(cursor.top()->text == NULL) ERROR(); if(strcmp(cursor.top()->text, TEXT) != 0) ERROR();}
#define CURSOR_NEXT()	{if(cursor.top()->next == NULL) ERROR(); cursor.top() = cursor.top()->next;}
#define CURSOR_NEXT_TEST(TYPE)	{CURSOR_NEXT(); if(cursor.top()->type != TYPE) ERROR() }
#define CURSOR_VERIFY_LABEL_TEXT(LABEL, VALUE) CURSOR_VERIFY_TEXT(LABEL); CURSOR_PUSH(JSON_STRING); CURSOR_VERIFY_TEXT(VALUE); cursor.pop();

#define DECHO()	{ std::cerr << "State " << state.top() << std::endl; }


	while (state.size() > 0) 
	{
		switch (state.top()) 
		{
			case 0:
				DECHO();
				// point cursor to the first child node
				CURSOR_PUSH(JSON_STRING);	

				// set the state stack
				state.pop();

				state.push(25);	// OtherFields
				state.push(1);	// MandatoryFields
				break;

			case 1:		// MandatoryFields -> Header Materials
				DECHO();
				// Nodes Surfaces Elements
				state.pop();

				state.push(18);	// Elements
				state.push(11);	// Nodes
				state.push(6);	// Materials
				state.push(2);	// Header
				break;

			case 2:		// Header -> VersionNumber FemModelType
				DECHO();

				CURSOR_VERIFY_TEXT("fem");	// header label must be "fem"

				CURSOR_PUSH(JSON_OBJECT);	
				CURSOR_PUSH(JSON_STRING);	

				// set the state stack
				state.pop();

				state.push(5);	// EndHeader
				state.push(4);	// FemModelType
				state.push(3);	// VersionNumber
				break;

			case 3:		// VersionNumber -> "version": "1.0"
				DECHO();
				CURSOR_VERIFY_TEXT("version");	// header label must be
				// "fem"
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("1.0");	// header label must be "fem"

				// reposition the cursor
				cursor.pop();	
				CURSOR_NEXT();	
				state.pop();
				break;

			case 4:		// <FemModelType> -> "type": "3D solid"
				DECHO();
				CURSOR_VERIFY_TEXT("type");	// header label must be "fem"
				CURSOR_PUSH(JSON_STRING);	// "version": -> "1.0"
				CURSOR_VERIFY_TEXT("3D solid");	// header label must be
				// "fem"

				// reposition the cursor
				cursor.pop();

				state.pop();

				// reposition the cursor
				break;

			case 5:		// EndHeader
				DECHO();
				cursor.pop();	
				cursor.pop();
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("materials");	// header label must be
				// "fem"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 6:		// Materials
				DECHO();
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(9);	// <MaterialsFollow>
				state.push(7);	// <Material>
				break;

			case 7:		// Material
				DECHO();
				CURSOR_PUSH(JSON_STRING);
				CURSOR_VERIFY_LABEL_TEXT("type", "linear elastic");
				material.type = fem::Material::MAT_LINEAR_ELASTIC;

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("label");
				CURSOR_PUSH(JSON_STRING);
				material.label.fromUtf8(cursor.top()->text);
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("E");
				CURSOR_PUSH(JSON_NUMBER);
				material.E = QString(cursor.top()->text).toDouble();
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("nu");
				CURSOR_PUSH(JSON_NUMBER);
				material.nu = QString(cursor.top()->text).toDouble();
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("fy");
				CURSOR_PUSH(JSON_NUMBER);
				material.fy = QString(cursor.top()->text).toDouble();
				cursor.pop();

				// update field
				state.pop();

				state.push(8);	// EndMaterial
				break;

			case 8:		// EndMaterial
				DECHO();
				if (cursor.top()->next != NULL)
					ERROR();
				cursor.pop();
				cursor.pop();

				// Material field is complete. Push material to the list
				this->model.material_list.push_back(material);

				state.pop();
				break;

			case 9:		// MaterialsFollow
				DECHO();
				// test the FIRST of fury
				if (cursor.top()->next == NULL) 
				{
					state.pop();

					state.push(10);	// EndMaterialsFollow
				} 
				else 
				{
					cursor.top() = cursor.top()->next;

					state.pop();

					state.push(9);	// MaterialsFollow
					state.push(7);	// Material
				}
				break;

			case 10:		// EndMaterialsFollow
				DECHO();
				// TODO
				cursor.pop();	
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("nodes");	// header label must be
				// "nodes"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 11:		// Nodes
				DECHO();
				CURSOR_PUSH(JSON_ARRAY);	
				state.pop();

				state.push(13);	// NodeFollow
				state.push(12);	// Node
				break;

			case 12:		// Node
				DECHO();
				CURSOR_PUSH(JSON_NUMBER);	// "nodes": [ [ -> 1, [
				state.pop();

				state.push(16);	// EndNode
				state.push(15);	// Coordinate
				state.push(14);	// NodeReference
				break;

			case 13:		// NodeFollow
				DECHO();
				// TODO test the FIRST of fury
				if (cursor.top()->next == NULL) {
					state.pop();

					state.push(17);	// EndNodes
				} else {
					CURSOR_NEXT_TEST(JSON_ARRAY);
					state.pop();

					state.push(13);	// NodeFollow
					state.push(12);	// Node
				}
				break;

			case 14:		// NodeReference
				DECHO();
				text = cursor.top()->text;
				ref = text.toULongLong();

				CURSOR_NEXT();
				if (cursor.top()->type != JSON_ARRAY)
					goto error;
				state.pop();
				break;

			case 15:		// Coordinate
				DECHO();
				CURSOR_PUSH(JSON_NUMBER);

				// get the vector components
				text = cursor.top()->text;
				v.x(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.y(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.z(text.toDouble());

				if (cursor.top()->next != NULL)
					goto error;
				cursor.pop();

				state.pop();
				break;

			case 16:		// EndNode
				DECHO();
				// TODO finish
				model.setNode(ref, v);

				cursor.pop();

				state.pop();
				break;

			case 17:		// EndNodes
				DECHO();
				// TODO finish
				cursor.pop();	
				cursor.pop();
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("elements");	// header label must be "nodes"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 18:		// Elements
				DECHO();
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(20);	// ElementFollow
				state.push(19);	// Element
				break;

			case 19:		// Element
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("type");

				CURSOR_PUSH(JSON_STRING);	
				// "tetrahedron"

				// clear the temp element
				element.nodes.clear();

				state.pop();

				state.push(23);	// MaterialReference
				switch (fem::Element::extractType(cursor.top()->text)) 
				{
					case fem::Element::FE_TETRAHEDRON4:
						element.type = fem::Element::FE_TETRAHEDRON4;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_TETRAHEDRON10:
						element.type = fem::Element::FE_TETRAHEDRON10;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON8:
						element.type = fem::Element::FE_HEXAHEDRON8;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON20:
						element.type = fem::Element::FE_HEXAHEDRON20;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON27:
						element.type = fem::Element::FE_HEXAHEDRON27;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_PRISM6:
						element.type = fem::Element::FE_PRISM6;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					default:
						std::cout << "unsupported element: " << state.
							top() << std::endl;
						goto unknown_error;
						break;
				}

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("nodes");
				CURSOR_PUSH(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);
				break;

			case 20:		// ElementsFollow
				DECHO();
				// TODO
				if (cursor.top()->next != NULL) {
					CURSOR_NEXT_TEST(JSON_OBJECT);

					state.pop();

					state.push(20);	// ElementsFollow
					state.push(19);	// Element
				} else {
					state.pop();

					state.push(24);	// EndElements
				}
				break;

			case 21:		// ElementFirstNode
				DECHO();
				// TODO
				text = cursor.top()->text;
				element.nodes.push_back(text.toULongLong());

				state.pop();
				break;

			case 22:		// ElementNextNode
				DECHO();
				CURSOR_NEXT_TEST(JSON_NUMBER);

				text = cursor.top()->text;
				element.nodes.push_back(text.toULongLong());

				state.pop();
				break;

			case 23:		// MaterialReference
				DECHO();
				cursor.pop();
				cursor.pop();
				if (cursor.top()->next == NULL) 
				{
					cursor.pop();
				} 
				else 
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					CURSOR_VERIFY_TEXT("material");
					CURSOR_PUSH(JSON_NUMBER);
					text = cursor.top()->text;
					model.setDefaultMaterial(text.toULongLong());
					cursor.pop();
					cursor.pop();
				}

				// push element
				model.pushElement(element);

				state.pop();
				break;

			case 24:	// EndElements
				DECHO();
				// TODO finish
				cursor.pop();	
				cursor.pop();

				state.pop();
				break;


			case 25:	// OtherFields
				DECHO();
				// TODO finish
				// test the FIRST
				if (cursor.top()->next == NULL) 
				{
					// TODO
					// no node restrictions
					// no load patterns
					// no combinations

					// reached the end of the document
					return ERR_OK;
				} 
				else 
				{
					cursor.top() = cursor.top()->next;	

					// verify first
					if (strcmp(cursor.top()->text, "node restrictions") == 0) {
						CURSOR_PUSH(JSON_ARRAY);	

						state.pop();

						state.push(29);	// AfterNodeRestrictions
						state.push(26);	// NodeRestrictions
					} else if (strcmp(cursor.top()->text, "load patterns") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	

						state.pop();

						state.push(30);	// LoadPatterns
					} else if (strcmp(cursor.top()->text, "load combinations") == 0) 
					{
						// TODO
						return ERR_OK;
					} else 
					{
						ERROR();
					}
				}
				break;

			case 26:		// NodeRestrictions
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();
				state.push(28);	// NodeRestrictionFollow
				state.push(27);	// NodeRestriction
				break;

			case 27:		// NodeRestriction
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);	

				// set the temps
				node_restrictions.reset();

				text = cursor.top()->text;
				ref = text.toULongLong();

				cursor.pop();
				CURSOR_NEXT_TEST(JSON_STRING);

				if (strcmp(cursor.top()->text, "dx") == 0) {
					if (cursor.top()->child->type == JSON_TRUE)
						node_restrictions.setdx();

					CURSOR_NEXT_TEST(JSON_STRING);
				}

				if (strcmp(cursor.top()->text, "dy") == 0) {
					if (cursor.top()->child->type == JSON_TRUE)
						node_restrictions.setdy();

					CURSOR_NEXT_TEST(JSON_STRING);
				}

				if (strcmp(cursor.top()->text, "dz") == 0) {
					if (cursor.top()->child->type == JSON_TRUE)
						node_restrictions.setdy();
				}

				if (cursor.top()->next != NULL)
					ERROR();

				// set the node restrictions
				model.pushNodeRestrictions(ref, node_restrictions);

				cursor.pop();	

				state.pop();
				break;

			case 28:		// NodeRestrictionFollow
				DECHO();
				// TODO finish
				if (cursor.top()->next == NULL) {	// EndNodeRestriction
					cursor.pop();	
					cursor.pop();	

					state.pop();
				} else {
					CURSOR_NEXT();

					cursor.pop();

					state.push(28);	// NodeRestrictionsFollow
					state.push(26);	// NodeRestrictions
				}
				break;

			case 29:		// AfterNodeRestrictions
				DECHO();
				// TODO
				if (cursor.top()->next == NULL) {
					// EOF
					return ERR_OK;
				}

				CURSOR_NEXT_TEST(JSON_STRING);

				if (strcmp(cursor.top()->text, "load patterns") == 0) {
					CURSOR_PUSH(JSON_ARRAY);	


					state.pop();

					state.push(30);	// LoadPatterns
				} else if (strcmp(cursor.top()->text, "load combinations") ==
						0) {
					// TODO
					return ERR_OK;
				} else {
					ERROR();
				}

				break;


			case 30:		// LoadPatterns
				DECHO();
				// TODO 
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(40);	// LoadPatternFollow
				state.push(31);	// LoadPattern
				break;

			case 31:		// LoadPattern
				DECHO();
				// TODO
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("label");
				CURSOR_PUSH(JSON_STRING);	
				load_pattern.clear();
				load_pattern.label = cursor.top()->text;

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);	


				if (strcmp(cursor.top()->text, "nodal loads") == 0) {
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(35);	// AfterNodalLoads
					state.push(32);	// NodalLoads
				} 
				else if (strcmp(cursor.top()->text, "node displacements") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(36);	// NodeDisplacements
				}
			       	else if (strcmp(cursor.top()->text, "domain loads") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(39);	// DomainLoads
				} 
				else if (strcmp(cursor.top()->text, "surface loads") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(35);	// SurfaceLoads
				} 
				else 
				{
					ERROR();
				}
				break;


			case 32:		// NodalLoads
				DECHO();
				state.pop();

				state.push(34);	// NodalLoadFollow
				state.push(33);	// NodalLoad
				break;

			case 33:		// NodalLoad
				DECHO();
				CURSOR_PUSH(JSON_STRING);	

				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);	

				text = cursor.top()->text;
				ref = text.toULongLong();

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("force");
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				state.push(15);	// Coordinate
				break;

			case 34:	// NodalLoadFollow
				DECHO();
				//TODO
				load_pattern.addNodalLoad(ref, v);

				cursor.pop();	// JSON_OBJECT -> "force" JSON_ARRAY
				cursor.pop();	// -> JSON_OBJECT "force"

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(34);	// NodalLoadFollow
					state.push(33);	// NodalLoad
				}
				break;

			case 35:	// AfterNodalLoads
				DECHO();
				//TODO
				cursor.pop();	// JSON_OBJECT -> "load patterns" JSON_ARRAY
				cursor.pop();	// -> "nodal loads"

				if(cursor.top()->next == NULL)
				{
					//TODO finish this
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					if (strcmp(cursor.top()->text, "node displacements") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	// "node displacements" JSON_ARRAY JSON_OBJECT

						state.pop();

						state.push(36);	// NodeDisplacements
					} 
					else if (strcmp(cursor.top()->text, "domain loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(39);	// DomainLoads
					} 
					else if (strcmp(cursor.top()->text, "surface loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(35);	// SurfaceLoads
					} 
					else 
					{
						ERROR();
					}
				}
				break;

			case 36:	// NodeDisplacements
				DECHO();
				state.pop();

				state.push(38);	// NodeDisplacementFollow
				state.push(37);	// NodeDisplacement
				break;

			case 37:	// NodeDisplacement
				CURSOR_PUSH(JSON_STRING);
				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);
				text = cursor.top()->text;
				ref = text.toULongLong();
				cursor.pop();
				CURSOR_NEXT_TEST(JSON_STRING);

				// CURSOR_VERIFY_TEXT("node");
				//TODO add support for node displacements
				break;

			case 38:	// NodeDisplacementFollow
				DECHO();
				//TODO  add support for node displacements

				// cursor.pop();	// JSON_OBJECT -> "force" JSON_ARRAY
				cursor.pop();	// -> JSON_OBJECT "node"

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(38);	// NodeDisplacementFollow
					state.push(37);	// NodeDisplacement
				}
				break;

			default:
				std::cout << "unsupported state: " << state.top() << std::endl;
				goto unknown_error;	// common way to handle all parser errors
				break;
		}
	}

	unsaved = false;
	return ERR_OK;

error:
	return ERR_PARSER_ERROR;

unknown_error:		// some programming error happened
	return ERR_UNKNOWN;

	//TODO undef all macros
#undef CURSOR_PUSH
#undef CURSOR_VERIFY_TEXT
}


enum Document::Error Document::save()
{
	QFile           file;
	// TODO check version

	// check if if the given file_name exists
	if (file_name == NULL)
		return ERR_FILE_NOT_FOUND;

	file.setFileName(*file_name);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
	{
		return ERR_WRITING_FILE;
	}
	QTextStream     out(&file);
	out << "{";
	// dump the header field
	out << "\"fem\":\n";
	out << "\t{";
	out << "\t\"version\": \"1.0\",\n";
	out << "\t\"type\": ";
	switch (document_type) {
		case TYPE_SOLID3D:
			out << "\"solid3d\"\n";
			break;

		default:
			out << "\"unknown\"\n";	// this should be seen as an error
			break;
	}
	out << "\t},\n";

	// dump the materials list
	out << "\"materials\": [";
	for (std::vector < fem::Material >::iterator it =
			model.material_list.begin(); it != model.material_list.end();
			it++) {
		// to print the comman between entries and avoiding printing it
		// after the last
		if (it != model.material_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		switch (it->type) {
			case fem::Material::MAT_LINEAR_ELASTIC:
				out << "{\"type\":" << "\"linear elastic\", \"label\": \"" <<
					it->label << "\", \"E\":" << it->E << ",\"nu\":" << it->
					nu << ", \"fy\": " << it->fy << "}";
				break;

			default:
				qWarning("defaulted while outputting");
				break;
		}
	}
	out << "\t],\n";

	// dump the nodes list
	out << "\"nodes\":[";
	for (std::map < size_t, fem::Node >::iterator it =
			model.node_list.begin(); it != model.node_list.end(); it++) {
		if (it != model.node_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "[" << it->first << ",[" << it->
			second.data[0] << "," << it->second.data[1] << "," << it->
			second.data[2] << "]]";

	}
	out << "\n\t],\n";

	// dump the elements list
	out << "\"elements\":[";
	int             material = 0;
	for (std::vector < fem::Element >::iterator it =
			model.element_list.begin(); it != model.element_list.end(); it++)
	{
		if (it != model.element_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "{\"type\":";
		// get the name of the element
		switch (it->type) {
			/*
			 * case fem::Element::FE_LINE2: out << "\"line2\", "; break;
			 * 
			 * case fem::Element::FE_TRIANGLE3: out << "\"triangle3\", ";
			 * break; 
			 */

			case fem::Element::FE_TETRAHEDRON4:
				out << "\"tetrahedron4\", ";
				break;

			case fem::Element::FE_HEXAHEDRON8:
				out << "\"hexahedron8\", ";
				break;

			case fem::Element::FE_TETRAHEDRON10:
				out << "\"tetrahedron10\", ";
				break;

				/*
				 * case fem::Element::FE_HEXAHEDRON20: out <<
				 * "\"hexahedron20\", "; break; 
				 */

			case fem::Element::FE_HEXAHEDRON20:
				out << "\"hexahedron28\", ";
				break;

			case fem::Element::FE_PRISM6:
				out << "\"prism6\", ";
				break;

			default:
				// TODO finish this
				out << "\"default\", ";
				qWarning("element defaulted");
				break;
		}
		// output the element's nodes
		out << "\"nodes\":[";
		for (std::vector < size_t >::iterator n = it->nodes.begin();
				n != it->nodes.end(); n++) {
			if (n != it->nodes.begin())
				out << ",";
			out << *n;
		}
		out << "]";
		// output the element's material
		if ((it->material != material)
				|| (it == model.element_list.begin())) {
			material = it->material;
			out << ", \"material\": " << material;
		}
		out << "}";
	}
	out << "\n\t],\n";

	// dump the load restrictions list
	out << "\"node restrictions\": [";
	for (std::map < size_t, fem::NodeRestrictions >::iterator it =
			model.node_restrictions_list.begin();
			it != model.node_restrictions_list.end(); it++) {
		// TODO test this
		if (it != model.node_restrictions_list.begin())
			out << ",";
		out << "\n\t\t";
		out << "{ \"node\":" << it->first;
		if (it->second.dx() == true)
			out << ", \"dx\":true";
		if (it->second.dy() == true)
			out << ", \"dy\":true";
		if (it->second.dz() == true)
			out << ", \"dz\":true";
		out << "}";
	}

	out << "\n\t],\n";

	// dump the load patterns list
	out << "\"load patterns\":[";
	for (std::vector < fem::LoadPattern >::iterator it =
			model.load_pattern_list.begin();
			it != model.load_pattern_list.end(); it++) {
		if (it != model.load_pattern_list.begin())
			out << ",";
		out << "\n\t\t{";
		out << "\t\"label\": \"" << it->label << "\"";
		// take care of the nodal loads
		if (!it->nodal_loads.empty()) {
			out << ",\n\t\t";
			out << "\"nodal loads\":[";
			for (std::map < size_t, fem::NodalLoad >::iterator n =
					it->nodal_loads.begin(); n != it->nodal_loads.end(); n++)
			{
				if (n != it->nodal_loads.begin())
					out << ",";
				out << "\n\t\t\t{";
				out << "\"node\":" << n->first;
				out << ", \"force\":" << "[" << n->second.force.
					x() << ", " << n->second.force.
					y() << ", " << n->second.force.z() << "]}";
			}
			out << "\n\t\t]";
		}
		// take care of the nodal displacements
		if (!it->nodal_displacements.empty()) {
			out << ",\n\t\t";
			out << "\"node displacements\":[";
			for (std::map < size_t, fem::NodalDisplacement >::iterator n =
					it->nodal_displacements.begin();
					n != it->nodal_displacements.end(); n++) {
				if (n != it->nodal_displacements.begin())
					out << ",";
				out << "\n\t\t\t{";
				out << "\"node\":" << n->first;
				out << ", \"displacement\":" << "[" << n->
					second.displacement.data[0] << ", " << n->second.
					displacement.data[1] << ", " << n->second.
					displacement.data[2] << "]}";
			}
			out << "\n\t\t]";
		}
		// take care of the domain displacements
		if (!it->domain_loads.empty()) {
			out << ",\n\t\t";
			out << "\"domain loads\":[";
			for (std::map < size_t, fem::DomainLoad >::iterator n =
					it->domain_loads.begin(); n != it->domain_loads.end();
					n++) {
				if (n != it->domain_loads.begin())
					out << ",";
				out << "\n\t\t\t{";
				out << "\"element\":" << n->first;
				out << ", ";
				out << "\"force\": [" << n->second.force.x() << "," << n->
					second.force.y() << "," << n->second.force.z() << "]";
				out << "}";
			}
			out << "\n\t\t\t]\n";
		}
		// take care of the surface loads
		// TODO finish surface loads

		out << "\t\t}\n";
	}
	out << "\t],\n";


	// dump the load combinations list
	out << "\"combinations\":[";
	// TODO finish combinations
	out << "\t]\n";

	out << "}\n";		// final, closing bracket

	// cleanup and exit
	// TODO see KDE/ext4 row on proper unix file_name writing
	file.flush();
	file.close();

	unsaved = false;
	return ERR_OK;
}


enum Document::Error Document::importMesh(QString file_name)
{
	QFile           mesh_file;

	mesh_file.setFileName(file_name);
	if (!mesh_file.open(QIODevice::ReadOnly | QIODevice::Text)) {	// failed 
		// 
		// to 
		// open 
		// file
		return ERR_FILE_OPEN;
	}
	// TODO import mesh from a Gmsh file
	FILE           *f = fdopen(mesh_file.handle(), "r");
	fem_model_import_msh(f, model);
	mesh_file.close();

	return ERR_OK;
}


void Document::selectNode(const size_t & node)
{
	selected_nodes[node] = true;
}


void Document::deselectNode(const size_t & node)
{
	selected_nodes.erase(node);
}


void Document::deselectAll()
{
	selected_nodes.clear();
}

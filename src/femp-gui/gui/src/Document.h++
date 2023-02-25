#ifndef FEMP_DOCUMENT_HPP
#define FEMP_DOCUMENT_HPP

#include "Project.h++"

// Qt includes
#include <QString>

class Document {
	public:
	enum Type { TYPE_NONE, TYPE_SOLID3D };

	public:
	Document();
	Document(const Document& copied);

	void clear();  // clears/frees everything

	/**
	 * Sets the file name
	 * @param file file name
	 */
	void setFileName(QString file);
	void clearFileName();

	/**
	 * Returns a QString with the file name
	 */
	QString getFileName() const;
	bool isFileNameNotSet() const;

	void setProjectType(Type type);

	/**
	 * Returns a reference to the Project object
	 */
	fem::Project& getProject();

	/**
	 * @brief setDirty sets the document as containing changes that haven't
	 * been saved to disk.
	 * @param dirty
	 */
	void setDirty(bool dirty = true);
	bool isDirty() const;

	protected:
	bool m_dirty;			 // true if this document suffered changes that are saveable
	Type m_documentType;	 // specifies the model type
	fem::Project m_project;	 // the FEM project
	QString m_filename;		 // path for the project's directory
};

#endif

#ifndef FEMP_DOCUMENT_HPP
#define FEMP_DOCUMENT_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDir>	// for the project path

#include "Project.h++"


class Document
{
public:
    enum Type { TYPE_NONE, TYPE_SOLID3D};

public:
    Document();
    Document(const Document &copied);
    ~Document();

    void clear();	// clears/frees everything

    /*!
     * Sets the file name
     */
    void setFileName(QString file);	// points to a file
    void clearFileName();

    /*!
     * Returns a QString with the file name
     */
    QString getFileName() const;
    bool isFileNameNotSet() const;

    void setProjectType(Type type);

    /*!
     * Returns a reference to the Project object
     */
    fem::Project &getProject();

    void setUnsaved(bool saved = false);


protected:
    bool m_unsaved;	// true if this document suffered changes that are saveable
    Type m_documentType;	// specifies the model type
    fem::Project m_project;	// the FEM project
    QString m_filename;	// path for the project's directory

};

#endif


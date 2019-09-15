#include "NewProjectWizardPage2.h++"

NewProjectWizardPage2::NewProjectWizardPage2()
{
    setupUi(this);

    // Register fields
    registerField("Project3DSolids", commandLink3DSolids);
}

bool NewProjectWizardPage2::validatePage()
{
    bool result = false;
    result |= commandLink3DSolids->isChecked();
    //TODO add more buttons when more project types are added

    return result;
}

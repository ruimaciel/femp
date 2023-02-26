#ifndef TABLE_FILTER_DIALOG_HPP
#define TABLE_FILTER_DIALOG_HPP

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
	class TableFilterDialog;
}

/**
 * Implements a dialog box which is used to toggle the visibility of each column
 * and filter the results After running the dialog, the status of each widget is
 * checked to tweak the visibility of each column in the table
 */
class TableFilterDialog : public QDialog {
	Q_OBJECT

	public:
	TableFilterDialog(QWidget* parent = nullptr);
	~TableFilterDialog();

#define MEMBER_HELPER(XX)                       \
	void set##XX##Visible(bool state);			\
	bool get##XX##Visible() const ;             

	MEMBER_HELPER(ElementReference);
	MEMBER_HELPER(ElementType);
	MEMBER_HELPER(NodeGlobalReference);
	MEMBER_HELPER(NodeLocalReference);
	MEMBER_HELPER(NodePositionX);
	MEMBER_HELPER(NodePositionY);
	MEMBER_HELPER(NodePositionZ);
	MEMBER_HELPER(NodeDisplacementsX);
	MEMBER_HELPER(NodeDisplacementsY);
	MEMBER_HELPER(NodeDisplacementsZ);
	MEMBER_HELPER(E11);
	MEMBER_HELPER(E22);
	MEMBER_HELPER(E33);
	MEMBER_HELPER(E12);
	MEMBER_HELPER(E23);
	MEMBER_HELPER(E13);
	MEMBER_HELPER(S11);
	MEMBER_HELPER(S22);
	MEMBER_HELPER(S33);
	MEMBER_HELPER(S12);
	MEMBER_HELPER(S23);
	MEMBER_HELPER(S13);
	MEMBER_HELPER(VonMises);
#undef MEMBER_HELPER

	private Q_SLOTS:
	void toggleElementsCheckboxes(bool);
	void toggleElementCheckbox(bool);

	void toggleNodeReferencesCheckboxes(bool);
	void toggleNodeReferenceCheckbox(bool);

	void toggleNodePositionsCheckboxes(bool);
	void toggleNodePositionCheckbox(bool);

	void toggleNodeDisplacementsCheckboxes(bool);
	void toggleNodeDisplacementsCheckbox(bool);

	void toggleStrainsCheckboxes(bool);
	void toggleStrainsCheckbox(bool);

	void toggleStressesCheckboxes(bool);
	void toggleStressesCheckbox(bool);

	private:
	std::unique_ptr<Ui::TableFilterDialog> m_ui;
};

#endif

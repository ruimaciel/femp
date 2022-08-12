#ifndef NODE_RESTRAINS_DIALOG_HPP
#define NODE_RESTRAINS_DIALOG_HPP

#include <libfemp/NodeRestrictions.h++>

#include "ui/ui_NodeRestrainDialog.h"

class NodeRestrainsDialog : public QDialog, private Ui_NodeRestrainDialog {
	Q_OBJECT

   public:
	enum Restraints { NONE = 0, RX = 0x01, RY = 0x02, RZ = 0x04 };

   public:
	explicit NodeRestrainsDialog(QWidget* parent = nullptr);

	int getRestraints();

	fem::NodeRestrictions getRestrictions() const;
};

#endif

#ifndef NODE_RESTRAINS_DIALOG_HPP
#define NODE_RESTRAINS_DIALOG_HPP

#include <libfemp/NodeRestrictions.hpp>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class NodeRestrainDialog;
}

class NodeRestrainsDialog : public QDialog {
	Q_OBJECT

	public:
	enum Restraints { NONE = 0, RX = 0x01, RY = 0x02, RZ = 0x04 };

	public:
	explicit NodeRestrainsDialog(QWidget* parent = nullptr);
	~NodeRestrainsDialog();

	int getRestraints();

	fem::NodeRestrictions getRestrictions() const;

	private:
	std::unique_ptr<Ui::NodeRestrainDialog> m_ui;
};

#endif

#include "InputWindow.h"

//default constructor
InputWindow::InputWindow(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::InputWindow)
{
	ui->setupUi(this);
}

//destructor
InputWindow::~InputWindow()
{
	delete ui;
}

//�������� Ű���带 �Է¹���
string InputWindow::find_show()
{
	this->close();
	return ui->name->text().toStdString();
}

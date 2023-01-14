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

//컨텐츠의 키워드를 입력받음
string InputWindow::find_show()
{
	this->close();
	return ui->name->text().toStdString();
}

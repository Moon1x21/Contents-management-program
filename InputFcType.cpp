#include "InputFcType.h"

//default constructor
InputFcType::InputFcType(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::InputFcType)
{
	ui->setupUi(this);
}

//destructor
InputFcType::~InputFcType()
{
	delete ui;
}

//type�� �������� ����
void InputFcType::find_pic()
{
	this->close();
	type = "����";
}

//type�� ���������� ����
void InputFcType::find_video()
{
	this->close();
	type = "������";
}

//type�� �ĳ������ ����
void InputFcType::find_panorama()
{
	this->close();
	type = "�ĳ��";
}
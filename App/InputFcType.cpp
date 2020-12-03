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

//type을 사진으로 저장
void InputFcType::find_pic()
{
	this->close();
	type = "사진";
}

//type을 동영상으로 저장
void InputFcType::find_video()
{
	this->close();
	type = "동영상";
}

//type을 파노라마으로 저장
void InputFcType::find_panorama()
{
	this->close();
	type = "파노라마";
}

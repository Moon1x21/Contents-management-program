#include "SaveContents.h"
#include "Application.h"

//default constructor
SaveContents::SaveContents(QWidget* parent): 
	QDialog(parent),
	ui(new Ui::SaveContents)
{
	ui->setupUi(this);
}

//destructor
SaveContents::~SaveContents()
{
	delete ui;
}

//컨텐츠 저장이 됨
void SaveContents::open_window()
{
	cname = ui->cname->text().toStdString();	//Contents nbame
	cdate = ui->c_date->text().toStdString();	//Contents date
	cevent = ui->cevent->text().toStdString();	//Event nbame
	cpeople = ui->cpeople->text().toStdString();	//People name
	cplace = ui->cplace->text().toStdString();	// place name
	ccontent = ui->c_content->text().toStdString();	//Content
	cfc = ui->c_fc->isChecked();	//fclist 포함 유무
	this->close();
}

//사진을 load
void SaveContents::load_pic()
{
	ui->widget->close();
	QFileDialog dlg;
	QString filepath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");
	QPixmap img;
	img.load(filepath);
	cfilepath = filepath.toStdString();	//contents path
	ctype = "사진";	//contents  type
	ui->display->setPixmap(img);
	ui->display->setScaledContents(true);
}

//동영상을 load
void SaveContents::load_video()
{
	ui->widget->close();
	ctype = "동영상";	//contents  type
}

//파노라마 load
void SaveContents::load_panorama()
{
	ui->widget->close();
	QFileDialog dlg;
	QString filepath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");
	QPixmap img;
	img.load(filepath);
	cfilepath = filepath.toStdString();	//contents path
	ctype = "파노라마";	//contents  type
	ui->display->setPixmap(img);
	ui->display->setScaledContents(true);
}
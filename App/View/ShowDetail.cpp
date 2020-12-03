#include "ShowDetail.h"



ShowDetail::ShowDetail(QWidget* parent ):
	QDialog(parent),
	ui(new Ui::ShowDetail)
{
	ui->setupUi(this);
}

ShowDetail::~ShowDetail()
{
	delete ui;
}

void ShowDetail::open_main()
{
	this->close();
	num = 0;
}

void ShowDetail::set(ItemType data)
{
	ui->cname->setText(QString::fromStdString(data.GetName()));
	ui->cdate->setText(QString::fromStdString(data.GetDtime()));
	ui->cevent->setText(QString::fromStdString(data.GetEvent()));
	ui->cpeople->setText(QString::fromStdString(data.GetPeople()));
	ui->cplace->setText(QString::fromStdString(data.GetPlace()));
	ui->ccontent->setText(QString::fromStdString(data.GetCon()));
	ui->viewpoint->setText(QString::number(data.GetView()));
	QPixmap img;
	img.load(QString::fromStdString(data.GetFile()));
	ui->display->setPixmap(img);
	ui->display->setScaledContents(true);
}

void ShowDetail::setfc(FileType data)
{
	ui->label->hide(); ui->label_3->hide(); ui->label_4->hide();
	ui->label_4->hide(); ui->label_5->hide(); ui->label_6->hide();
	ui->ccontent ->hide(); ui->cdate ->hide(); ui->cplace ->hide();
	ui->cpeople ->hide(); ui->cevent ->hide(); ui->viewpoint ->hide();
	ui->cname->setText(QString::fromStdString(data.GetName()));
	QPixmap img;
	img.load(QString::fromStdString(data.GetFilePath()));
	ui->display->setPixmap(img);
	ui->display->setScaledContents(true);
}

void ShowDetail::Get_Back()
{
	this->close();
	num = 1;
}

void ShowDetail::Get_Next()
{
	this->close();
	num = 2;
}

void ShowDetail::hide_button()
{
	ui->next->hide();
	ui->back->hide();
}


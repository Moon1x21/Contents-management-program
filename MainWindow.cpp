#include "pch.h"
#include"MainWindow.h"

//default constructor
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::QtWidgetsApplication1Class)
{
    ui->setupUi(this);
}

//destructor
QtWidgetsApplication1::~QtWidgetsApplication1()
{
    delete ui;
}

//�޴� â�� ȭ�鿡 ���
void QtWidgetsApplication1::start()
{
    this->hide();
    Application app;
    app.setModal(true);
    app.exec();
   
}
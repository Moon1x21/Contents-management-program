#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    /**
	*	default constructor
	*/
    QtWidgetsApplication1(QWidget *parent = 0);

    /**
    *	destructor
    */
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class *ui;

private slots:

    /**
    *	@brief	�޴� â�� ȭ�鿡 ���
    *	@pre	��ư Ŭ��
    *	@post	�޴� â�� ȭ�鿡 �����
    */
    void start();
};

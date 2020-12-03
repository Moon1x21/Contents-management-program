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
    *	@brief	메뉴 창을 화면에 띄움
    *	@pre	버튼 클릭
    *	@post	메뉴 창이 화면에 띄워짐
    */
    void start();
};

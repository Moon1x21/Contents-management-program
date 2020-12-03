#pragma once
#include "pch.h"
#include <QDialog>
#include <qfiledialog.h>
#include "ui_ShowDetail.h"


namespace Ui {
	class ShowDetail;
}

class ShowDetail :public QDialog
{
	friend class Application;

	Q_OBJECT
public:
	ShowDetail(QWidget* parent = 0);
	~ShowDetail();
	void applyApp(Application* app) { this->app = app; }
	void applyFc(FcMenu* fc) { this->fc = fc; }
	void set(ItemType data);
	void setfc(FileType data);
	int Getnum() { return num; }
private slots:
	void open_main();
	void Get_Back();
	void Get_Next();
	void hide_button();

private:
	Ui::ShowDetail* ui;
	Application* app;
	FcMenu* fc;
	int num;
};

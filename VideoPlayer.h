#pragma once
#include "pch.h"
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QDialog>
#include <QWidget>
#include <qfiledialog.h>
#include "ui_VideoPlayer.h"

namespace Ui {
	class VideoPlayer;
}
class VideoPlayer :public QWidget
{
	friend class SaveContents;
	Q_OBJECT

public:
	explicit VideoPlayer(QWidget* parent = 0);
	~VideoPlayer();

	//void applySave(SaveContents* save) { this->save = save; }


private slots:
	//void play();
private:

	Ui::VideoPlayer* ui;
	string cfilepath;
};
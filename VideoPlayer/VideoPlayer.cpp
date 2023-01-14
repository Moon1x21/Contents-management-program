#include "VideoPlayer.h"

VideoPlayer::VideoPlayer(QWidget* parent):
	QWidget(parent),
	ui(new Ui::VideoPlayer)
{
	ui->setupUi(this);
}

VideoPlayer::~VideoPlayer()
{
	delete ui;
}

#include "QtLrcRL2AssAeg.h"

#include "CLrc2Ass.h"

#include<QFileDialog>
#include <QDebug>

QtLrcRL2AssAeg::QtLrcRL2AssAeg(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::QtLrcRL2AssAegClass()) {
	ui->setupUi(this);

	ui->lineLrc->setText("E:/Project_water/Karaoke/Crest/孟婆湯/孟婆湯.lrc");
	ui->lineAss->setText("E:/Project_water/Karaoke/Crest/孟婆湯/孟婆湯.ass");

	connect(ui->btnLrc, &QPushButton::clicked,
		this, [&] {
			QString file = QFileDialog::getOpenFileName(this);

			qDebug() << file;
			ui->lineLrc->setText(file);
		});
	connect(ui->btnAss, &QPushButton::clicked,
		this, [&] {
			QString file = QFileDialog::getOpenFileName(this);

			qDebug() << file;
			ui->lineAss->setText(file);
		});
	connect(ui->btnRun, &QPushButton::clicked,
		this, [&] {
			QString fileLrc = ui->lineLrc->text();
			QString fileAss = ui->lineAss->text();

			CLrc2Ass* obj = new CLrc2Ass;
			obj->SetLrcPath(fileLrc);
			obj->SetAssPath(fileAss);
			obj->Run();
			delete obj;
		});
}

QtLrcRL2AssAeg::~QtLrcRL2AssAeg() {
	delete ui;
}

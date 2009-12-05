#include "MainWindowInterface.h"
#include <iostream>
#include <QtGui/QtGui>
#include "ImageProcessing.h"
MainWindowInterface::MainWindowInterface(QMainWindow *parent)
    : QMainWindow(parent)
{
	this->showMaximized();
	
    ui.setupUi(this);
	filename.clear();
	

	ui.menuStyle->setEnabled(0);
	ui.menuBasic_Operations->setEnabled(0);
	ui.actionSave->setEnabled(0);
	zoom = false;
	QWidget::connect(ui.actionOpen , SIGNAL(triggered()), this, SLOT(open()));
	QWidget::connect(ui.actionSave , SIGNAL(triggered()), this, SLOT(save()));
	QWidget::connect(ui.actionClose , SIGNAL(triggered()), this, SLOT(close()));
	QWidget::connect(ui.actionExit , SIGNAL(triggered()), this, SLOT(exit_p()));
	QWidget::connect(ui.actionZoom_To_Fit , SIGNAL(toggled(bool)), this, SLOT(zoomchecked(bool)));
	
	QWidget::connect(ui.actionEdge_Detection , SIGNAL(triggered()), this, SLOT(edgedet()));
	QWidget::connect(ui.actionGuassian_Blur , SIGNAL(triggered()), this, SLOT(blur()));
	QWidget::connect(ui.actionCanny , SIGNAL(triggered()), this, SLOT(canny()));
	QWidget::connect(ui.actionSegmentation , SIGNAL(triggered()), this, SLOT(segmentation()));

	QWidget::connect(ui.actionNPR1 , SIGNAL(triggered()), this, SLOT(appnpr1()));
	QWidget::connect(ui.actionNPR2_10 , SIGNAL(triggered()), this, SLOT(appnpr2_1()));
	QWidget::connect(ui.actionNPR2_20 , SIGNAL(triggered()), this, SLOT(appnpr2_2()));
	QWidget::connect(ui.actionNPR2_30 , SIGNAL(triggered()), this, SLOT(appnpr2_3()));
	QWidget::connect(ui.actionNPR_3, SIGNAL(triggered()), this, SLOT(appnpr3()));
	QWidget::connect(ui.actionHalftoning, SIGNAL(triggered()), this, SLOT(halftoning()));
	
}
void MainWindowInterface::disp()
{
	if(zoom)
	{
		ui.label->setPixmap(QPixmap::fromImage(output.scaled(ui.label->width(),ui.label->height(),Qt::KeepAspectRatio)));
		ui.label_2->setPixmap(QPixmap::fromImage(source.scaled(ui.label_2->width(),ui.label_2->height(),Qt::KeepAspectRatio)));
	}
	else
	{
		ui.label_2->setPixmap(QPixmap::fromImage(source));
		ui.label->setPixmap(QPixmap::fromImage(output));
	}
}
void MainWindowInterface::zoomchecked(bool stat)
{
	zoom = stat;
	disp();
	std::cout<<zoom;
}
void MainWindowInterface::open()
{
	this->filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "/",
                                                 tr("Image (*.*)")); 
	if(!filename.isNull())
	{	source.fill(0);
		source.load(filename);
		ui.menuStyle->setEnabled(1);
		ui.actionSave->setEnabled(1);
		ui.menuBasic_Operations->setEnabled(1);
		output = source;
		disp();
	}	
}

void MainWindowInterface::save()
{
	
	const QPixmap *mp = ui.label->pixmap();
	QString savefileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
                                                 "/",
                                                 tr("Jpeg Image (*.jpg)")); 
	mp->save(savefileName);
	
}
void MainWindowInterface::close()
{
	ui.label_2->setText("Source");
	ui.label->setText("Result");
	ui.menuStyle->setEnabled(0);
}
void MainWindowInterface::exit_p()
{
	std::cout<<"exit_p";
}
void MainWindowInterface::showGui()
{
	this->show();	
}

void MainWindowInterface::blur()
{
	output.fill(0);
	output= QBlur(source);
	disp();
}
void MainWindowInterface::appnpr1()
{
	output = NPR(source);
	disp();
}
void MainWindowInterface::appnpr2_1()
{
	output = NPR2(source,10);
	disp();
}
void MainWindowInterface::appnpr2_2()
{
	output = NPR2(source,20);
	disp();
}
void MainWindowInterface::appnpr2_3()
{
	output = NPR2(source,30);
	disp();
}
void MainWindowInterface::edgedet()
{	output.fill(0);
	output = QSobel(source);
	disp();
}
void MainWindowInterface::canny()
{	output.fill(0);
	output = QCanny(source);
	disp();
}

void MainWindowInterface::segmentation()
{	
	//output = source;#
	output.fill(0);
	output=QSegmentation(source,50);
	disp();
}

void MainWindowInterface::appnpr3()
{	
	//output = source;#
	output.fill(0);
	output=QAdd(QSegmentation(source,40),QCanny(source)); //Requires fixing
	disp();
}

void MainWindowInterface::halftoning()
{	
	//output = source;#
	output.fill(0);
	output=QHalftoning(QRgbToGray(source));
	disp();
}

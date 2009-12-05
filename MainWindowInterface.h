
#ifndef MainWindowInterface_H
#define MainWindowInterface_H

#include <QtGui/QtGui>
#include <direct.h>
#include "UI/Ui_MainWindow.h"
class QMdiArea;
class MainWindowInterface : public QMainWindow
{
   Q_OBJECT
public:
    MainWindowInterface(QMainWindow *parent = 0);
	void showGui();
	
public slots:
	void open();
	void close();
	void save();
	void exit_p();

	void appnpr1();
	void appnpr2_1();
	void appnpr2_2();
	void appnpr2_3();
	void appnpr3();
	void halftoning();
	
	void blur();
	void edgedet();
	void canny();
	void segmentation();
	void zoomchecked(bool);
	
private:
	// Data for Storing the project status
	QString filename;
	QImage source;
	QImage output;
	bool zoom;
	void disp();
	Ui::MainWindow ui;
};

#endif
#include <QtGui\QApplication>
#include <QtGui\QtGui>
#include <iostream>
#include <conio.h>
#include <math.h>
#include "ColorModel.h"
#include "ImageProcessing.h"
#include <cv.h >

#include <QtGui\QApplication>
#include "MainWindowInterface.h"
 int main(int argc, char *argv[])
 {
	QApplication app(argc, argv);
	MainWindowInterface GUI;
	GUI.showGui();
    return app.exec();
 }
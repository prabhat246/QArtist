#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H
#include <cv.h>
#include <highgui.h>
#include "ColorModel.h"
#include <QtGui/QtGui>
#include "regiontbl.h"

QImage QRgbToGray(QImage &img);
QImage QSobel(QImage &img);
QImage QConv(QImage &img,double filter[3][3]);
QImage QBlur(QImage &img);
QImage QThreshold(QImage &img, int Thresold);/// Image should be grayscale
QImage NPR(QImage &img);/// Image should be grayscale
QImage NPR2(QImage &img, int threshold);/// Image should be grayscale
QImage QCanny(QImage &img);
QImage QAdd(QImage &img, QImage &add);
QImage QHalftoning(QImage &img);
QImage QSegmentation(QImage &imgq, int threshold);


#endif
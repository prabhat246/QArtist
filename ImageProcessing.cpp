#include "imageprocessing.h"

#include <iostream>
QImage QRgbToGray(QImage &img)
{
	QImage temp = img.copy(0,0,img.width(),img.height());

	for(int j =0; j<temp.height(); j++)
		for(int i =0; i<temp.width();i++)	
		{
			QRgb gotpixel = img.pixel(i,j);
			int r = qRed(gotpixel);
			int g = qGreen(gotpixel);
			int b = qBlue(gotpixel);
			int gray = (int)(0.30*r + 0.59*g + 0.11*b);
			//int gray = (int)(0.33*r + 0.33*g + 0.33*b);
			temp.setPixel(i,j,qRgb(gray,gray,gray));
		}
	return temp;
}
QImage QSobel(QImage &img)
{
	QImage temp = img.copy(0,0,img.width(),img.height());
	const int filterWidth = 3;
	const int filterHeight = 3 ;
	
	double filter[3][3] =  
	{ 
		-1, -2, -1,
		 0,  0,  0,
		 1,  2,  1
	};
	double filter2[3][3] =  
	{ 
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1
	};
	int dimX = temp.height();
	int dimY = temp.width();
	for(int j =0; j<temp.height(); j++)
		for(int i =0; i<temp.width();i++)	
		{
			double fred = 0.0, fgreen=0.0, fblue = 0.0;
			//multiply every value of the filter with corresponding image pixel 
				for(int filterX = 0; filterX < filterWidth; filterX++) 
				for(int filterY = 0; filterY < filterHeight; filterY++) 
				{ 
					int imageX = (j - filterWidth / 2 + filterX + dimX) % dimX; 
					int imageY = (i - filterHeight / 2 + filterY + dimY) % dimY; 
					QRgb gotpixel = img.pixel(imageY,imageX);
					int r = qRed(gotpixel);
					int g = qGreen(gotpixel);
					int b = qBlue(gotpixel);

					fred += r* filter[filterX][filterY];
					fgreen += g* filter[filterX][filterY];
					fblue += b* filter[filterX][filterY];				}

			temp.setPixel(i,j,qRgb((int)fred,(int)fgreen,(int)fblue));
		}
	return temp;
}
QImage QConv(QImage &img,double filter[3][3])
{
	QImage temp = img.copy(0,0,img.width(),img.height());
	const int filterWidth = 3;
	const int filterHeight = 3 ;

	int dimX = temp.height();
	int dimY = temp.width();
	for(int j =0; j<temp.height(); j++)
		for(int i =0; i<temp.width();i++)	
		{
			double fred = 0.0, fgreen=0.0, fblue = 0.0;
			//multiply every value of the filter with corresponding image pixel 
				for(int filterX = 0; filterX < filterWidth; filterX++) 
				for(int filterY = 0; filterY < filterHeight; filterY++) 
				{ 
					int imageX = (j - filterWidth / 2 + filterX + dimX) % dimX; 
					int imageY = (i - filterHeight / 2 + filterY + dimY) % dimY; 
					QRgb gotpixel = img.pixel(imageY,imageX);
					int r = qRed(gotpixel);
					int g = qGreen(gotpixel);
					int b = qBlue(gotpixel);
					fred += r* filter[filterX][filterY]/111;
					fgreen += g* filter[filterX][filterY]/111;
					fblue += b* filter[filterX][filterY]/111;
				}

			temp.setPixel(i,j,qRgb((int)fred,(int)fgreen,(int)fblue));
		}
	return temp;
}
QImage QBlur(QImage &img)
{
	double filter[3][3] =  
	{ 
		1,	10,	1,
		10,	67,	10, 
		1,	10,	1
	};
	return QConv(img,filter);
}


QImage QThreshold(QImage &img, int Thresold)/// Image should be grayscale
{
	QImage temp = img.copy(0,0,img.width(),img.height());
	int dimX = temp.height();
	int dimY = temp.width();
	for(int j =0; j<temp.height(); j++)
		for(int i =0; i<temp.width();i++)	
		{
	
			QRgb gotpixel = img.pixel(i,j);
			int r = qRed(gotpixel);
			if (r<Thresold) 
				r =0;
			else
				r = 255;
			temp.setPixel(i,j,qRgb((int)r,(int)r,(int)r));
		}
	return temp;
}


QImage QHalftoning(QImage &img)/// Image should be grayscale
{
	QImage temp = img.copy(0,0,img.width(),img.height());

	for(int j =0; j<temp.height(); j=j+2)
		for(int i =0; i<temp.width();i=i+2)	
		{
			QRgb gotpixel0 = img.pixel(i,j);
			QRgb gotpixel1 = img.pixel(i,j+1);
			QRgb gotpixel2 = img.pixel(i+1,j);
			QRgb gotpixel3 = img.pixel(i+1,j+1);
			int r0 = qRed(gotpixel0);
			int r1 = qRed(gotpixel1);
			int r2 = qRed(gotpixel2);
			int r3 = qRed(gotpixel3);
			int r = (r0 + r1 + r2 + r3)/4;
			if (r >= 0 && r<51)
			{ r0 = 0; r1 = 0; r2=0; r3=0;
			}
			else if (r>=51 && r<102)
			{ r0 = 0; r1 = 0; r2=0; r3=255;
			}
			else if (r>=102 && r<153)
			{ r0 = 0; r1 = 255; r2=0; r3=255;
			}
			else if (r>=153 && r<205)
			{
				r0 = 0; r1 = 255; r2=255; r3=255;
			}
			else
			{ r0 = 255; r1 = 255; r2=255; r3=255;
			}
			temp.setPixel(i,j,    qRgb((int)r0,(int)r0,(int)r0));
			temp.setPixel(i,j+1,  qRgb((int)r1,(int)r1,(int)r1));
			temp.setPixel(i+1,j,  qRgb((int)r2,(int)r2,(int)r2));
			temp.setPixel(i+1,j+1,qRgb((int)r3,(int)r3,(int)r3));
		}
	return temp;
}
QImage NPR(QImage &img)/// Image should be grayscale
{
	QImage temp = img.copy(0,0,img.width(),img.height());
	// How big is your box of pastels?
	double BaseColors = 72; // 1-360, step 1, Default = 72

	double Q = 360 / BaseColors;
	double H = 0,S = 0,V = 0;
	for(int y = 0; y < img.height(); y++)
	{
		for (int x = 0; x < img.width(); x++)
		{
					
			QRgb gotpixel = img.pixel(x,y);
			int R = qRed(gotpixel);
			int G = qGreen(gotpixel);
			int B = qBlue(gotpixel);
			double H,S,V;
			EvanRGBtoHSV(R,G,B,H,S,V);
			
			H = Q*(double)floor(H/Q); // Normalize Hue
			if (S > .15) // Compress Saturation // Default S > .15
			{
				S = ( (0.35*(S-0.15)) / (1.0-0.15) ) + 0.15;
			}
			if (V > 0.05) // Compress Value //Default V > 0.05
			{
				V = ( (0.15*(V-0.05)) / (1.0-0.05) ) + 0.85;
			} 
			else // Near Black Pixels
			{
				S = 0; // turn them gray
				V += 0.75;
			}
			EvanHSVtoRGB(H,S,V,R,G,B);
			temp.setPixel(x,y,qRgb((int)R,(int)G,(int)B));
		}
		}
	return temp;
	}
QImage NPR2(QImage &img, int threshold)/// Image should be grayscale
{
	
	IplImage* outimg = cvCreateImage(cvSize(img.width(), img.height()),8,3);
	
	for(int j =0; j<img.height(); j++)
		for(int i =0; i<img.width();i++)	
		{
			QRgb gotpixel = img.pixel(i,j);
			CvScalar tmp;
			tmp.val[0] = qBlue(gotpixel);
			tmp.val[1] = qGreen(gotpixel);
			tmp.val[2] = qRed(gotpixel);
			cvSet2D(outimg,j,i,tmp);
		}
	
	int block_size = 1000;
	CvMemStorage *storage;
	IplImage *image0 = 0, *image1 = 0;
	int  threshold1, threshold2;
	int  l,level = 4;
	CvSeq *comp;
	storage = cvCreateMemStorage ( block_size );

    outimg->width &= -(1<<level);
    outimg->height &= -(1<<level);

    image0 = cvCloneImage( outimg );
    image1 = cvCloneImage( outimg );
    // segmentation of the color image
    l = 1;
    threshold1 =255;
	threshold2 =threshold;

     cvPyrSegmentation(image0, image1, storage, &comp, 
                      level, threshold1+1, threshold2+1);

	 cvSaveImage("temp.jpg",image1);
	 
	 return QImage("temp.jpg");
}

QImage QCanny(QImage &img)
{
	
	IplImage* outimg = cvCreateImage(cvSize(img.width(), img.height()),8,3);
	
	for(int j =0; j<img.height(); j++)
		for(int i =0; i<img.width();i++)	
		{
			QRgb gotpixel = img.pixel(i,j);
			CvScalar tmp;
			tmp.val[0] = qBlue(gotpixel);
			tmp.val[1] = qGreen(gotpixel);
			tmp.val[2] = qRed(gotpixel);
			cvSet2D(outimg,j,i,tmp);
		}
	
	IplImage *edge = 0,*gray = 0, *cedge;
	
	gray = cvCreateImage(cvSize(outimg->width,outimg->height), IPL_DEPTH_8U, 1);
    edge = cvCreateImage(cvSize(outimg->width,outimg->height), IPL_DEPTH_8U, 1);

	cedge = cvCreateImage(cvSize(outimg->width,outimg->height), IPL_DEPTH_8U, 3);
	cvCvtColor(outimg, gray, CV_BGR2GRAY);

	cvSmooth( gray, edge, CV_BLUR, 3, 3, 0, 0 );

	cvCanny(gray,edge,50,240,3);
	//cvZero( cedge );
    // copy edge points
    //cvCopy( outimg, cedge, edge );

     cvNot( edge, gray );
	 cvSaveImage("temp.jpg",gray);	 
	 return QImage("temp.jpg");
}

QImage QAdd(QImage &img, QImage &add)
{
	QImage temp = img.copy(0,0,img.width(),img.height());	
	
	for(int j =0; j<img.height(); j++)
		for(int i =0; i<img.width();i++)	
		{
			QRgb gotpixel1 = img.pixel(i,j);
			QRgb gotpixel2 = add.pixel(i,j);
			if(qRed(gotpixel2) >= 240)
				temp.setPixel(i,j,gotpixel1);
			else
				temp.setPixel(i,j,gotpixel2);
		}
	return temp;
}
Photo *PIC;
QImage QSegmentation(QImage &imgq, int threshold)/// Image should be grayscale
{
	
	IplImage* img = cvCreateImage(cvSize(imgq.width(), imgq.height()),8,3);
	
	for(int j =0; j<imgq.height(); j++)
		for(int i =0; i<imgq.width();i++)	
		{
			QRgb gotpixel = imgq.pixel(i,j);
			CvScalar tmp;
			tmp.val[0] = qBlue(gotpixel);
			tmp.val[1] = qGreen(gotpixel);
			tmp.val[2] = qRed(gotpixel);
			cvSet2D(img,j,i,tmp);
		}
	PIC = new Photo();
	PIC->setThreshold(threshold);
	PIC->convertFromCV(img);
	std::cout<<"\nSegmenting image...";
    PIC->segment();

	std::cout<<"\nAveraging out regions...";
    PIC->avgSegmentColours();

    IplImage* outimg = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    uchar *outdata= (uchar *)outimg->imageData;

    PIC->convertToCV(outimg);
	
	QImage temp = imgq.copy(0,0,imgq.width(),imgq.height());
		
	for(int j =0; j<imgq.height(); j++)
		for(int i =0; i<imgq.width();i++)	
		{
			CvScalar tmp = cvGet2D(outimg,j,i);
			temp.setPixel(i,j,qRgb(tmp.val[2],tmp.val[1],tmp.val[0]));
		}
	delete(PIC);
	return temp;
}
QImage QCanny2(QImage &img)
{
	QImage temp = img.copy(0,0,img.width(),img.height());
	const int filterWidth = 3;
	const int filterHeight = 3 ;
	
	double filter[3][3] =  
	{ 
		-1, -2, -1,
		 0,  0,  0,
		 1,  2,  1
	};
	double filter2[3][3] =  
	{ 
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1
	};
	int dimX = temp.height();
	int dimY = temp.width();
	for(int j =0; j<temp.height(); j++)
		for(int i =0; i<temp.width();i++)	
		{
			double fred = 0.0, fgreen=0.0, fblue = 0.0;
			//multiply every value of the filter with corresponding image pixel 
				for(int filterX = 0; filterX < filterWidth; filterX++) 
				for(int filterY = 0; filterY < filterHeight; filterY++) 
				{ 
					int imageX = (j - filterWidth / 2 + filterX + dimX) % dimX; 
					int imageY = (i - filterHeight / 2 + filterY + dimY) % dimY; 
					QRgb gotpixel = img.pixel(imageY,imageX);
					int r = qRed(gotpixel);
					int g = qGreen(gotpixel);
					int b = qBlue(gotpixel);

					fred += r* filter[filterX][filterY];
					fgreen += g* filter[filterX][filterY];
					fblue += b* filter[filterX][filterY];				}

			temp.setPixel(i,j,qRgb((int)fred,(int)fgreen,(int)fblue));
		}
	return temp;
}
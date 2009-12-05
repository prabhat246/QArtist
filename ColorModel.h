#ifndef COLOR_MODEL_H
#define COLOR_MODEL_H

#include<math.h>

double EvanMax3(double x, double y, double z);
double EvanMin3(double x, double y, double z);
double AngleConstrain(double MyAngle);
void EvanHSVtoRGB(double H, double S, double V, int &bR, int &bG, int &bB);
void EvanRGBtoHSV(int R, int G, int B, double &outH, double &outS, double &outV);


#endif 
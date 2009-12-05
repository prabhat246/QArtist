#include "ColorModel.h"

double EvanMax3(double x, double y, double z)
{
	return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

double EvanMin3(double x, double y, double z)
{
	return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

double AngleConstrain(double MyAngle)
{
	// Makes sure that 0.0 <= MyAngle < 360.0
	// Wraps around the value if its outside this range
	if (MyAngle >= 360.0)
	{
		MyAngle -= floor(MyAngle / 360.0) * 360.0;
	}
	if (MyAngle < 0.0)
	{
		MyAngle += 360.0;
	}
	return MyAngle;
}
void EvanHSVtoRGB(double H, double S, double V, int &bR, int &bG, int &bB)
{
	const double HSV_UNDEFINED = -999.0;
	// Parameters must satisfy the following ranges:
	// 0.0 <= H < 360.0
	// 0.0 <= S <= 1.0
	// 0.0 <= V <= 1.0

	// Handle special case first
	if (S == 0.0 || H == HSV_UNDEFINED)
	{
		int x = (int)(V * 255.0);
		bR = x;
		bG = x;
		bB = x;
		return;
	}

	if (H >= 360.0)
	{
		H = AngleConstrain(H);
	}

	double R = V, G = V, B = V;
	double Hi = floor(H / 60.0);
	double f = H / 60.0 - Hi;
	double p = V * (1.0 - S);
	double q = V * (1.0 - f * S);
	double t = V * (1.0 - (1.0 - f) * S);
	if (Hi == 0.0)
	{
		R = V;
		G = t;
		B = p;
	}
	else if (Hi == 1.0)
	{
		R = q;
		G = V;
		B = p;
	}
	else if (Hi == 2.0)
	{
		R = p;
		G = V;
		B = t;
	}
	else if (Hi == 3.0)
	{
		R = p;
		G = q;
		B = V;
	}
	else if (Hi == 4.0)
	{
		R = t;
		G = p;
		B = V;
	}
	else if (Hi == 5.0)
	{
		R = V;
		G = p;
		B = q;
	}

	int iR = (int)(R * 255.0);
	int iG = (int)(G * 255.0);
	int iB = (int)(B * 255.0);
	bR = (int)iR;
	bG = (int)iG;
	bB = (int)iB;
}

void EvanRGBtoHSV(int R, int G, int B, double &outH, double &outS, double &outV)
{
	const double HSV_UNDEFINED = -999.0;
	// R, G, and B must range from 0 to 255
	// Ouput value ranges:
	// outH - 0.0 to 360.0
	// outS - 0.0 to 1.0
	// outV - 0.0 to 1.0

	double dR = (double)R / 255.0;
	double dG = (double)G / 255.0;
	double dB = (double)B / 255.0;
	double dmaxRGB = EvanMax3(dR, dG, dB);
	double dminRGB = EvanMin3(dR, dG, dB);
	double delta = dmaxRGB - dminRGB;

	// Set value
	outV = dmaxRGB;

	// Handle special case
	if (dmaxRGB == 0)
	{
		outH = HSV_UNDEFINED;
		outS = 0.0;
		return;
	}

	outS = delta / dmaxRGB;
	if (dmaxRGB == dminRGB)
	{
		outH = HSV_UNDEFINED;
		return;
	}

	// Finally, compute hue
	if (dR == dmaxRGB)
	{
		outH = (dG - dB) / delta * 60.0;
	}
	else if (dG == dmaxRGB)
	{
		outH = (2.0 + (dB - dR) / delta) * 60.0;
	}
	else //if (dB == dmaxRGB)
	{
		outH = (4.0 + (dR - dG) / delta) * 60.0;
	}

	if (outH < 0)
	{
		outH += 360.0;
	}
}

#pragma once
#include "Fourier.h"
#define MATH_PI 3.14159265359
#define MATH_DOUBLE_PI 6.28318530718
class Wave
{
public:
	static double sine(double amplitude, double frequency, double time, double phase);
	static double triangle(double amplitude, double frequency, double time, double phase);
	static double square(double amplitude, double frequency, double time, double phase);
	static double sawtooth(double amplitude, double frequency, double time, double phase);
};


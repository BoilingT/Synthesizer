#pragma once
#include "Wave.h"
#include "AudioCapture.h"
#include "ChronoTime.h"


class Synthesizer
{
private:
	AudioCapture audioCapture;

public:



	Synthesizer();

	//Play a frequency (Hz) for a period of time (s)
	void play(int seconds, double frequency);
	void stop();

	static void callback(const void* in, const void* out, unsigned long frameCount);
};


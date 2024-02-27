#pragma once
#include "Wave.h"
#include "AudioCapture.h"

class Synthesizer
{
private:
	double sampleRate = 44100;
	AudioCapture audioCapture;

public:
	Synthesizer();

	//Play a frequency (Hz) for a period of time (s)
	void play(int seconds, double frequency);
	void stop();
};


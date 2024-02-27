#pragma once
#include <iostream>
#include "portaudio.h"

class AudioCapture
{
private:
	double sampleRate = 44100;
	double framesPerBuffer = 256;
	PaStream* stream = nullptr;

public:
	AudioCapture(double sampleRate);
	~AudioCapture();
	//Open an audio I/O stream
	void OpenStream();
	void CloseStream();
	//Calls the callback function to perform the audio processing
	void StartStream();
	//Stops the audio processing
	void StopStream();
	void Sleep(int seconds);

private:
	//Handle captured audio
	static int PaStreamCallback(const void* input,
		void* output,
		unsigned long frameCount,
		const PaStreamCallbackTimeInfo* timeInfo,
		PaStreamCallbackFlags statusFlags,
		void* userData);
};


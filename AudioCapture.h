#pragma once
#include <iostream>
#include "portaudio.h"

class AudioCapture
{
private:
	double sampleRate = 44100;
	double framesPerBuffer = 254;
	int inputChannels = 0;
	int outputChannels = 2;

	PaStream* stream = nullptr;

	typedef void AudioCallback(const void* input, const void* output, unsigned long frameCount);

public:
	AudioCapture(double sampleRate, AudioCallback* audioCallback);
	~AudioCapture();
	//Open an audio I/O stream
	void OpenStream();
	//Close the audio I/O stream
	void CloseStream();
	//Calls the callback function to perform the audio processing
	void StartStream();
	//Stops the audio processing on the current stream
	void StopStream();
	void Sleep(int seconds);

private:
	//Process the I/O audio
	static int PaStreamCallback(const void* input,
		void* output,
		unsigned long frameCount,
		const PaStreamCallbackTimeInfo* timeInfo,
		PaStreamCallbackFlags statusFlags,
		void* userData);
};


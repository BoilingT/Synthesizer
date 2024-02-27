#include "AudioCapture.h"

typedef void AudioCallback(const void* input, const void* output, unsigned long frameCount);

static AudioCallback* audioCallbackPtr;

AudioCapture::AudioCapture(double sampleRate, AudioCallback* audioCallback)
{
	std::cout << "Initializing..." << std::endl;
	audioCallbackPtr = audioCallback;

	AudioCapture::sampleRate = sampleRate;
	//Init PortAudio
	PaError error = Pa_Initialize();
	if (error != paNoError)
	{
		std::cout << "ERROR::INIT: " << Pa_GetErrorText(error) << std::endl;
	}
	std::cout << "Initialized" << std::endl;
}

AudioCapture::~AudioCapture()
{
	std::cout << "Terminating..." << std::endl;
	PaError error = Pa_Terminate();
	if (error != paNoError)
	{
		std::cout << "ERROR::TERMINATION: " << Pa_GetErrorText(error) << std::endl;
		return;
	}
	std::cout << "Terminated" << std::endl;
}

void AudioCapture::OpenStream()
{
	std::cout << "Opening stream..." << std::endl;

	float data = 0;
	PaError error = Pa_OpenDefaultStream(&stream,
		0,
		2,
		paFloat32,
		sampleRate,
		framesPerBuffer,
		PaStreamCallback,
		&data);

	if (error != paNoError)
	{
		std::cout << "ERROR::OPEN::STREAM: " << Pa_GetErrorText(error) << std::endl;
		return;
	}
	std::cout << "Stream opened" << std::endl;
}

void AudioCapture::CloseStream()
{
	std::cout << "Closing stream..." << std::endl;

	PaError error = Pa_CloseStream(stream);
	if (error != paNoError)
	{
		std::cout << "ERROR::CLOSE::STREAM: " << Pa_GetErrorText(error) << std::endl;
		return;
	}
	std::cout << "Closed stream" << std::endl;
}

void AudioCapture::StartStream()
{
	std::cout << "Starting stream..." << std::endl;

	PaError error = Pa_StartStream(stream);
	if (error != paNoError)
	{
		std::cout << "ERROR::START::STREAM: " << Pa_GetErrorText(error) << std::endl;
		return;
	}
}

void AudioCapture::StopStream()
{
	std::cout << "Stopping stream..." << std::endl;

	PaError error = Pa_StopStream(stream);
	if (error != paNoError)
	{
		std::cout << "ERROR::STOP::STREAM: " << Pa_GetErrorText(error) << std::endl;
		return;

	}
	std::cout << "Stopped stream" << std::endl;
}

void AudioCapture::Sleep(int seconds)
{
	Pa_Sleep(1000 * seconds);
}

typedef struct
{
	float left_phase;
	float right_phase;
} paTestData;

int AudioCapture::PaStreamCallback(const void* input, void* output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
	audioCallbackPtr(input, output, frameCount);
	return 0;
}


#include "Synthesizer.h"
static ChronoTime stopwatch;
static double t;
static double sampleRate = 44100;

Synthesizer::Synthesizer() : audioCapture(sampleRate, &callback)
{

}

void Synthesizer::play(int seconds, double frequency)
{
	audioCapture.OpenStream();
	audioCapture.StartStream();
	audioCapture.Sleep(seconds);
	audioCapture.StopStream();
	audioCapture.CloseStream();
}

void Synthesizer::stop()
{
	audioCapture.StopStream();
	audioCapture.CloseStream();
}

void Synthesizer::callback(const void* input, const void* output, unsigned long frameCount)
{
	float* out = (float*) output;
	float* in = (float*) input;

	double deltaTime = 1.f / sampleRate;
	for (int i = 0; i < frameCount * 2; i+=2)
	{
		float sineValue = Wave::value(0.3f, 840, t);
		out[i] = sineValue;
		out[i + 1] = sineValue;

		t += deltaTime;
	}
//std::cout << "Callback called" << std::endl;
}

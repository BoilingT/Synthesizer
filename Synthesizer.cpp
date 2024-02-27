#include "Synthesizer.h"

Synthesizer::Synthesizer() : audioCapture(sampleRate)
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

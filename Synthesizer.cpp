#include "Synthesizer.h"
static ChronoTime stopwatch;
static double t;
static double sampleRate = 44100;

static struct Note
{
public:
	double C = 261.63f;
	double D = 293.66f;
	double E = 329.63f;
	double F = 349.23f;
	double G = 392.00f;
	double A = 440.00f;
	double B = 493.88f;
};

struct Choord
{
	double notes[3];

	double sinewave(double amplitude, double time)
	{
		return Wave::sine(amplitude, notes[0], time, 0) + Wave::sine(amplitude, notes[1], time, 0) + Wave::sine(amplitude, notes[2], time, 0);
	}
};

static Choord currentChoord;

Synthesizer::Synthesizer() : audioCapture(sampleRate, &callback)
{
	currentChoord = { Note().C, Note().E, Note().G };
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

/*
	Calculate the frequency bands from the input by
	converting the input amplitudes into a wave function that can
	be inserted into a Fourier Transform which can produce
	the frequencies as a function of time.

	Things to learn:
	-Programming Mathematic Algorithms
	-Fourier Series
	-Fourier Transform

	Things learned:

	*Fourier Series (Analyzes f(x))*:
	* By doing a sum of sine and cosine waves a function can be made that is similar to another function
	* Video: https://www.youtube.com/watch?v=aalANrz7bi8&list=PLSQl0a2vh4HCLqA-rhMi_Z_WnBkD3wUka&index=86

	* Fourier Transform ()*
	* Definition: "The Fourier transform is an analysis process, decomposing a complex-valued function f(x) into its
	* constituent frequencies and their amplitudes. The inverse process is synthesis, which recreates f(x) from its transform."

	Method:
	* Take all the amplitudes as inputs and treat them as values for an entire function.
	* Separate n number of frequency bands in the function from the given amplitudes.
	* Return the frequency bands from the operation with information about their frequency and amplitude.
	* Sort the bands by frequency and store them in a list
*/
void Synthesizer::callback(const void* input, const void* output, unsigned long frameCount)
{
	float* out = (float*) output;
	float* in = (float*) input;

	double amplitude = 0.1f;
	double deltaTime = 1.f / sampleRate;
	for (int i = 0; i < frameCount * 2; i+=2)
	{
		float sineValue = currentChoord.sinewave(amplitude, t);
		out[i] = sineValue;
		out[i + 1] = sineValue;

		t += deltaTime;
	}
//std::cout << "Callback called" << std::endl;
}

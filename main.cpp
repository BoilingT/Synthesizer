#include <Windows.h>
#include <iostream>
#include "Synthesizer.h"

int main()
{
	Synthesizer synth;

	synth.play(5, 440);

	return 0;
}
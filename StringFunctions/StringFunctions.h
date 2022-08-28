#pragma once
#include <string>

class StringFunctions
{
	int x;

public:

	StringFunctions(int x);

	int AddValue(int y);

	int HandleStringD(const char* inputString, char* outputBuffer, int outputBufferLength);

	int HandleStringE(char* inputString, char* outputBuffer);
};
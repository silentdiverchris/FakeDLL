#pragma once
#include <string>

class FakeDLL 
{
	int x;

public:

	FakeDLL(int x);

	int AddValue(int y);

	//int HandleStringA(char* inputStr, char* outputStr);

	int HandleStringD(const char* inputString, char* outputBuffer, int outputBufferLength);
};
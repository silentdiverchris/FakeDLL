#include "pch.h"
#include "FakeDLL.h"
#include <vector>

FakeDLL::FakeDLL(int x) {
	this->x = x;
}

int FakeDLL::AddValue(int y) {
	return this->x + y;
}

/// <summary>
/// Return the first outputBufferLength bytes of the input, and return error 999 if the input was too short
/// </summary>
int FakeDLL::HandleStringD(const char* inputString, char* outputBuffer, int outputBufferLength)
{
	errno_t errNo = 0;

	if (strlen(inputString) >= outputBufferLength)
	{
		outputBuffer = new char[outputBufferLength]();

		errNo = strcpy_s(outputBuffer, outputBufferLength, inputString);

		//stringCopy(outputStr, buffLen, inputStr);
	}
	else
	{
		errNo = 999;
	}

	return errNo;
}

//void stringCopy(char* dest, int maxLength, char const* source)
//{
//	char* end = dest + maxLength - 1;
//	while (dest != end && *source != '\0') 
//	{
//		*dest = *source;
//		++dest;
//		++source;
//	}
//	*dest = '\0';
//}

extern "C" __declspec(dllexport) void* Create(int x)
{
	return (void*) new FakeDLL(x);
}

extern "C" __declspec(dllexport) int AddValue(FakeDLL* obj, int y)
{
	return (int) obj->AddValue(y);
}

extern "C" __declspec(dllexport) int HandleStringD(FakeDLL* obj, const char* inputString, char* outputBuffer, int outputBufferLength)
{
	return (int)obj->HandleStringD(inputString, outputBuffer, outputBufferLength);
}

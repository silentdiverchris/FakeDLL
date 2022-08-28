#include "pch.h"
#include "StringFunctions.h"

StringFunctions::StringFunctions(int x) {
	this->x = x;
}

int StringFunctions::AddValue(int y) {
	return this->x + y;
}

/// <summary>
/// Return the first outputBufferLength bytes of the input, and return error 999 if the input was too short
/// </summary>
int StringFunctions::HandleStringD(const char* inputString, char* outputBuffer, int outputBufferLength)
{
	errno_t errNo = 0;

	inputString = "98765432109876543210";

	//ULONG ulSize = strlen(sampleString) + sizeof(char);
	//char* outBuff = NULL;

	if (strlen(inputString) >= outputBufferLength)
	{
		//outputBuffer = new char[outputBufferLength + 1]();

		outputBuffer = (char*)::malloc(outputBufferLength + 1);

		errNo = strcpy_s(outputBuffer, outputBufferLength, inputString);

		//stringCopy(outputStr, buffLen, inputStr);
	}
	else
	{
		errNo = 9999;
	}

	return errNo;
}

int StringFunctions::HandleStringE(char* inputString, char* outputBuffer)
{
	errno_t errNo = strcpy_s(outputBuffer, strlen(inputString), inputString);
	//strcpy(outputBuffer, inputString);

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
	return (void*) new StringFunctions(x);
}

extern "C" __declspec(dllexport) int AddValue(StringFunctions * obj, int y)
{
	return (int)obj->AddValue(y);
}

extern "C" __declspec(dllexport) int HandleStringD(StringFunctions * obj, const char* inputString, char* outputBuffer, int outputBufferLength)
{
	return (int)obj->HandleStringD(inputString, outputBuffer, outputBufferLength);
}

extern "C" __declspec(dllexport) int HandleStringE(StringFunctions * obj, char* inputString, char* outputBuffer)
{
	return (int)obj->HandleStringE(inputString, outputBuffer);
}
#include "pch.h"
#include "FakeDLL.h"
#include <vector>

FakeDLL::FakeDLL(int x) {
	this->x = x;
}

int FakeDLL::AddValue(int y) {
	return this->x + y;
}

int FakeDLL::HandleStringA(char* inputStr, char* outputStr)
{
	int buffLen = strlen(inputStr) + 1;
	outputStr = new char[buffLen]();

	errno_t errNo = strcpy_s(outputStr, buffLen, inputStr);
	//stringCopy(outputStr, buffLen, inputStr);
	//strcpy(outputStr, inputStr);

	return errNo;
}

int FakeDLL::HandleStringB(const std::string& inputStr, const std::string& outputStr)
{
	//int buffLen = 5;
	//
	//std::vector<char> outputVector(buffLen);

	//std:copy(inputStr + 0, inputStr + buffLen, buffLen);

	//outputStr = new char[5]();
	//outputStr = "set static";

	return 1;
}

std::string FakeDLL::HandleStringC(const std::string& inputStr)
{
	return "Blah blah";
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

extern "C" __declspec(dllexport) int HandleStringA(FakeDLL * obj, char* inputStr, char* outputStr)
{
	return (int)obj->HandleStringA(inputStr, outputStr);
}

extern "C" __declspec(dllexport) int HandleStringB(FakeDLL * obj, const std::string & inputStr, const std::string & outputStr)
{
	return (int)obj->HandleStringB(inputStr, outputStr);
}

extern "C" __declspec(dllexport) std::string HandleStringC(FakeDLL * obj, const std::string & inputStr)
{
	return (std::string)obj->HandleStringC(inputStr);
}
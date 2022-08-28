#pragma once
#include <string>

class FakeDLL 
{
	int x;

public:

	FakeDLL(int x);

	int AddValue(int y);

	int HandleStringA(char* inputStr, char* outputStr);

	int HandleStringB(const std::string& inputStr, const std::string& outputStr);

	std::string HandleStringC(const std::string& inputStr);
};
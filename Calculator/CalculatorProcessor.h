#pragma once
#include "wx/wx.h"
#include<string>

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _calcProcessor;
	int baseNumber = 0;
	int x = 0;
	int y = 0;
public:
	static CalculatorProcessor* GetInstance();
	void SetBaseNumber(int number);

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetHexdecimal();
	std::string GetBinary();
	std::string GetDecimal();
	int GetMod();

	int GetAdd();
	int GetSub();
	int GetMult();
	int GetDiv();

	std::string GetEquals();
};



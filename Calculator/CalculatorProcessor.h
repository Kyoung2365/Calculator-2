#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"
#include "IBaseCommand.h"
#include<string>


class CalculatorProcessor
{
private:
	static CalculatorProcessor* _calcProcessor;
	int Operator;
	int _valueX = 0;
	int _valueY = 0;
	int baseNumber = 0;
public:
	CalculatorProcessor() {}
	static CalculatorProcessor* GetInstance();
	void SetBaseNumber(int _number);
	void SetValue(int x, int y);
	void SetOperator(int _operator);

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetHexdecimal();
	std::string GetBinary();
	std::string GetDecimal();
	

	int GetAdd();
	int GetSub();
	int GetMult();
	int GetDiv();
	int GetMod();

	std::string GetEquals();
};



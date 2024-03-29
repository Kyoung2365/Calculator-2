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
	int baseNumber = 0;
	int baseNumber2 = 0;
public:
	CalculatorProcessor() {}
	static CalculatorProcessor* GetInstance();
	void SetBaseNumber(int _number);
	void SetBaseNumber2(int _number2);
	void SetOperator(int _operator);

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetHexdecimal();
	std::string GetBinary();
	std::string GetDecimal();

	std::string GetSin();
	std::string GetCos();
	std::string GetTan();
	

	static int GetAdd(int x, int y);
	static int GetSub(int x, int y);
	static int GetMult(int x, int y);
	static int GetDiv(int x, int y);
	static int GetMod(int x, int y);

	std::string GetEquals(int x, int y);
};



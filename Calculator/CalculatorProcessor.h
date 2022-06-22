#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"
#include "IBaseCommand.h"
#include<string>


class CalculatorProcessor : public IBaseCommand
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _calcProcessor;
	int baseNumber = 0;
	int Operator;
public:
	static CalculatorProcessor* GetInstance();
	void SetBaseNumber(int _number);
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
	void Execute();
};



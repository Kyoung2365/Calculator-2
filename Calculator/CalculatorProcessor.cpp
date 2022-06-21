
#include "CalculatorProcessor.h"
#include <string>

CalculatorProcessor* CalculatorProcessor::_calcProcessor = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance() {
	if (_calcProcessor == nullptr) {
		_calcProcessor = new CalculatorProcessor();
	}
	return _calcProcessor;
}

void CalculatorProcessor::SetBaseNumber(int _number) {
	baseNumber = _number;
}

void CalculatorProcessor::SetOperator(int _operator) {
	Operator = _operator;
}

std::string CalculatorProcessor::GetHexdecimal() {
	std::string results = "";
	int number = baseNumber;
	while (number > 0) {
		int mod = number % 16;
		if (mod < 10) {
			results = std::to_string(mod) + results;
		}
		else if (mod == 10) {
			results = "A" + results;
		}
		else if (mod == 11) {
			results = "B" + results;
		}
		else if (mod == 12) {
			results = "C" + results;
		}
		else if (mod == 13) {
			results = "D" + results;
		}
		else if (mod == 14) {
			results = "E" + results;
		}
		else if (mod == 15) {
			results = "F" + results;
		}
		number = number / 16;
	}
	results = "0x" + results;
	return results;
}

std::string CalculatorProcessor::GetBinary() {
	std::string results = "";
	int number = baseNumber;
	for (int i = 0; i < 32; i++) {
		if (number % 2 == 0) {
			results = "0" + results;
		}
		else {
			results = "1" + results;
		}
		number = number / 2;
	}
	return results;
}

std::string CalculatorProcessor::GetDecimal() {
	return std::to_string(baseNumber);
}

std::string CalculatorProcessor::GetEquals() {
	int result = 0;
	int sign = Operator;
	switch (sign) {
	case 1024:
		result = GetAdd();
		break;
	case 1025:
		result = GetSub();
		break;
	case 1026:
		result = GetMult();
		break;
	case 1027:
		result = GetDiv();
		break;
	case 1033:
		result = GetMod();
		break;
	}	
	return std::to_string(result);
}

int CalculatorProcessor::GetAdd() {
	return baseNumber + baseNumber;
}

int CalculatorProcessor::GetSub() {
	return baseNumber - baseNumber;
}

int CalculatorProcessor::GetMult() {
	return baseNumber * baseNumber;
}

int CalculatorProcessor::GetDiv() {
	return baseNumber / baseNumber;
}

int CalculatorProcessor::GetMod() {
	return baseNumber % baseNumber;
}

void CalculatorProcessor::Execute() {
	GetAdd();
	GetSub();
	GetMult();
	GetDiv();
}
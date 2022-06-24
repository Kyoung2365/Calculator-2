
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
void CalculatorProcessor::SetBaseNumber2(int _number2) {
	baseNumber2 = _number2;
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

std::string CalculatorProcessor::GetEquals(int x, int y) {
	int result = -1;
	int sign = Operator;
	sign = sign - OP_OFFSET;
	switch (sign) {
	case 0:
		result = GetAdd(x, y);
		break;
	case 1:
		result = GetSub(x, y);
		break;
	case 2:
		result = GetMult(x, y);
		break;
	case 3:
		result = GetDiv(x, y);
		break;
	case 9:
		result = GetMod(x, y);
		break;
	}	
	return std::to_string(result);
}

int CalculatorProcessor::GetAdd(int x, int y) {
	return x + y;
}

int CalculatorProcessor::GetSub(int x, int y) {
	return x - y;
}

int CalculatorProcessor::GetMult(int x, int y) {
	return x * y;
}

int CalculatorProcessor::GetDiv(int x, int y) {
	return x / y;
}

int CalculatorProcessor::GetMod(int x, int y) {
	return x % y;
}
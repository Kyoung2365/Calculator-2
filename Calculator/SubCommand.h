#pragma once
#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class SubCommand : public IBaseCommand {
private:
	CalculatorProcessor* _processor = nullptr;
	int _valueX = 0;
	int _valueY = 0;
public:
	SubCommand(CalculatorProcessor* processor, int x, int y) {
		_processor = processor;
		_valueX = x;
		_valueY = y;
	}

	void Execute() {
		_processor->SetValue(_valueX, _valueY);
	}
};

#pragma once
#include "IBaseCommand.h"
#include "CalculatorProcessor.h"

class ModCommand : public IBaseCommand {
private:
	CalculatorProcessor* _processor = nullptr;
	int _operator;
	int _valueX = 0;
	int _valueY = 0;
public:
	ModCommand(CalculatorProcessor* processor, int op, int x, int y) {
		_processor = processor;
		_operator = op;
		_valueX = x;
		_valueY = y;
	}

	void Execute() {
		_processor->GetEquals(_valueX, _valueY);
	}
};

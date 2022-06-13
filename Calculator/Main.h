#pragma once
#include "wx/wx.h"
#include "Screen.h"
class Main : public wxApp
{

private:
	Screen* screen = nullptr;
public:
	virtual bool OnInit();
};


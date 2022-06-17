#pragma once
#include "wx/wx.h"
#include "Calc.h"
#include "Screen.h"

const int OP_OFFSET = 1024;

enum Button {
	ID_0_BUTTON = 0,
	ID_1_BUTTON = 1,
	ID_2_BUTTON = 2,
	ID_3_BUTTON = 3,
	ID_4_BUTTON = 4,
	ID_5_BUTTON = 5,
	ID_6_BUTTON = 6,
	ID_7_BUTTON = 7,
	ID_8_BUTTON = 8,
	ID_9_BUTTON = 9,

	ID_DECI_BUTTON,
	ID_SIGN_BUTTON,
	ID_ADD_BUTTON = OP_OFFSET + Calc::OP_ADD,
	ID_SUB_BUTTON = OP_OFFSET + Calc::OP_SUB,
	ID_MUL_BUTTON = OP_OFFSET + Calc::OP_MUL,
	ID_DIV_BUTTON = OP_OFFSET + Calc::OP_DIV,
	ID_CLR_BUTTON,
	ID_EQUAL_BUTTON,
	ID_HEX_BUTTON,
	ID_BIN_BUTTON,
	ID_DEC_BUTTON,
	ID_MOD_BUTTON
};

class ButtonFactory : public wxWindow
{
public:
    wxButton* CreateNumButton(Screen* screen, int num, wxSize& size);
	wxButton* CreateAddButton(Screen* screen, wxSize& size);
	wxButton* CreateSubButton(Screen* screen, wxSize& size);
	wxButton* CreateMultButton(Screen* screen, wxSize& size);
	wxButton* CreateDivButton(Screen* screen, wxSize& size);
	wxButton* CreateClrButton(Screen* screen, wxSize& size);
	wxButton* CreateEqualsButton(Screen* screen, wxSize& size);
	wxButton* CreateDeciButton(Screen* screen, wxSize& size);
	wxButton* CreateSignButton(Screen* screen, wxSize& size);
	wxButton* CreateHexButton(Screen* screen, wxSize& size);
	wxButton* CreateBinButton(Screen* screen, wxSize& size);
	wxButton* CreateDecButton(Screen* screen, wxSize& size);
	wxButton* CreateModButton(Screen* screen, wxSize& size);
};



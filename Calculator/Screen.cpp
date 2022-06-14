#include "Screen.h"
#include "Calc.h"

const int OP_OFFSET = 1024;

enum event_ids {
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

//wxBEGIN_EVENT_TABLE(Screen, wxFrame)
//EVT_BUTTON(ID_0_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_1_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_2_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_3_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_4_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_5_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_6_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_7_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_8_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_9_BUTTON, Screen::OnButtonClick)
//EVT_BUTTON(ID_DECI_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_SIGN_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_ADD_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_SUB_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_MUL_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_DIV_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_CLR_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_EQUAL_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_HEX_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_BIN_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_DEC_BUTTON, Screen::SignButtonClick)
//EVT_BUTTON(ID_MOD_BUTTON, Screen::SignButtonClick)
//wxEND_EVENT_TABLE()

Screen::Screen() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(100, 100), wxSize(500, 500),
	wxCLOSE_BOX | wxCAPTION) {

	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	Display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);
	Display->Disable();
	wxBoxSizer* displaySizer = new wxBoxSizer(wxHORIZONTAL);
	displaySizer->Add(Display, 1, wxEXPAND | wxALL, 0);
	topSizer->Add(displaySizer, 0, wxEXPAND, 0);
	topSizer->AddSpacer(10);

	wxGridSizer* grid = new wxGridSizer(4, 0, 0);
	wxSize buttonSize(64, 64);
	numButtons.resize(10);
	for (int num = 0; num < 10; ++num) {
		numButtons[num] = new wxButton(this, num, std::to_string(num),
			wxDefaultPosition, buttonSize);
		numButtons[num]->Bind(wxEVT_BUTTON, &Screen::OnButtonClick, this);
	}
	addButton = new wxButton(this, ID_ADD_BUTTON, "+", wxDefaultPosition, buttonSize);
	addButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	subButton = new wxButton(this, ID_SUB_BUTTON, "-", wxDefaultPosition, buttonSize);
	subButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	multButton = new wxButton(this, ID_MUL_BUTTON, "x", wxDefaultPosition, buttonSize);
	multButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	divButton = new wxButton(this, ID_DIV_BUTTON, "/", wxDefaultPosition, buttonSize);
	divButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);

	clrButton = new wxButton(this, ID_CLR_BUTTON, "C", wxDefaultPosition, buttonSize);
	clrButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	equalsButton = new wxButton(this, ID_EQUAL_BUTTON, "=", wxDefaultPosition, buttonSize);
	equalsButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);

	deciButton = new wxButton(this, ID_DECI_BUTTON, ".", wxDefaultPosition, buttonSize);
	deciButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	signButton = new wxButton(this, ID_SIGN_BUTTON, "+/-", wxDefaultPosition, buttonSize);
	signButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	hexButton = new wxButton(this, ID_HEX_BUTTON, "HEX", wxDefaultPosition, buttonSize);
	hexButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	binButton = new wxButton(this, ID_BIN_BUTTON, "BIN", wxDefaultPosition, buttonSize);
	binButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	decButton = new wxButton(this, ID_DEC_BUTTON, "DEC", wxDefaultPosition, buttonSize);
	decButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);
	modButton = new wxButton(this, ID_MOD_BUTTON, "MOD", wxDefaultPosition, buttonSize);
	modButton->Bind(wxEVT_BUTTON, &Screen::SignButtonClick, this);

	grid->Add(hexButton, 1, wxEXPAND, 0);
	grid->Add(binButton, 1, wxEXPAND, 0);
	grid->Add(decButton, 1, wxEXPAND, 0);
	grid->Add(modButton, 1, wxEXPAND, 0);

	for (int num = 7; num <= 9; ++num) {
		grid->Add(numButtons[num], 1, wxEXPAND, 0);
	}
	grid->Add(divButton, 1, wxEXPAND, 0);
	for (int num = 4; num <= 6; ++num) {
		grid->Add(numButtons[num], 1, wxEXPAND, 0);
	}
	grid->Add(multButton, 1, wxEXPAND, 0);
	for (int num = 1; num <= 3; ++num) {
		grid->Add(numButtons[num], 1, wxEXPAND, 0);
	}
	grid->Add(subButton, 1, wxEXPAND, 0);

	grid->Add(signButton, 1, wxEXPAND, 0);
	grid->Add(numButtons[0], 1, wxEXPAND, 0);
	grid->Add(deciButton, 1, wxEXPAND, 0);
	grid->Add(addButton, 1, wxEXPAND, 0);



	grid->AddStretchSpacer();
	grid->AddStretchSpacer();
	grid->Add(clrButton, 1, wxEXPAND, 0);
	grid->Add(equalsButton, 1, wxEXPAND, 0);

	topSizer->Add(grid, 1, wxEXPAND, 0);

	SetSizerAndFit(topSizer);
}

void Screen::OnButtonClick(wxCommandEvent& evt) {
	wxString id = wxString::Format(wxT("%d"), evt.GetId());
	id.Append(wxString(""));
	Display->AppendText(id);
}

void Screen::SignButtonClick(wxCommandEvent& evt) {
	int id = evt.GetId();
	switch (id) {
	case ID_ADD_BUTTON:
		Display->AppendText("+");
		break;
	case ID_SUB_BUTTON:
		Display->AppendText("-");
		break;
	case ID_MUL_BUTTON:
		Display->AppendText("*");
		break;
	case ID_DIV_BUTTON:
		Display->AppendText("/");
		break;
	case ID_DECI_BUTTON:
		Display->AppendText(".");
		break;
	case ID_SIGN_BUTTON:
		Display->AppendText("-");
		break;
	case ID_EQUAL_BUTTON:
		Display->AppendText("=");
		break;
	case ID_CLR_BUTTON:
		Display->AppendText("CLR");
		break;
	case ID_HEX_BUTTON:
		Display->AppendText("HEX");
		break;
	case ID_BIN_BUTTON:
		Display->AppendText("BIN");
		break;
	case ID_DEC_BUTTON:
		Display->AppendText("DEC");
		break;
	case ID_MOD_BUTTON:
		Display->AppendText("MOD");
		break;
	}
}
Screen::~Screen() {

}
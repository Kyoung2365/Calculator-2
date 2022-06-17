#include "Screen.h"
#include "ButtonFactory.h"

wxBEGIN_EVENT_TABLE(Screen, wxFrame)
EVT_BUTTON(ID_0_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_1_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_2_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_3_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_4_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_5_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_6_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_7_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_8_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_9_BUTTON, Screen::OnButtonClick)
EVT_BUTTON(ID_DECI_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_SIGN_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_ADD_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_SUB_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_MUL_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_DIV_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_CLR_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_EQUAL_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_HEX_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_BIN_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_DEC_BUTTON, Screen::SignButtonClick)
EVT_BUTTON(ID_MOD_BUTTON, Screen::SignButtonClick)
wxEND_EVENT_TABLE();

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

	ButtonFactory Button;

	for (int num = 0; num < 10; num++) {
		numButtons[num] = Button.CreateNumButton(this, num, buttonSize);
	}

	addButton = Button.CreateAddButton(this, buttonSize);
	subButton = Button.CreateSubButton(this, buttonSize);
	multButton = Button.CreateMultButton(this, buttonSize);
	divButton = Button.CreateDivButton(this, buttonSize);
	clrButton = Button.CreateClrButton(this, buttonSize);
	equalsButton = Button.CreateEqualsButton(this, buttonSize);
	deciButton = Button.CreateDeciButton(this, buttonSize);
	signButton = Button.CreateSignButton(this, buttonSize);
	hexButton = Button.CreateHexButton(this, buttonSize);
	binButton = Button.CreateBinButton(this, buttonSize);
	decButton = Button.CreateDecButton(this, buttonSize);
	modButton = Button.CreateModButton(this, buttonSize);

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

Screen::~Screen() {

}
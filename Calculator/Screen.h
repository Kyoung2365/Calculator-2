#pragma once
#include "wx/wx.h"
#include <vector>

class Screen : public wxFrame
{
private:
	wxTextCtrl* Display;
	std::vector<wxButton*> numButtons;
	wxButton* hexButton;
	wxButton* binButton;
	wxButton* decButton;
	wxButton* modButton;
	wxButton* deciButton;
	wxButton* signButton;
	wxButton* addButton;
	wxButton* subButton;
	wxButton* multButton;
	wxButton* divButton;
	wxButton* clrButton;
	wxButton* equalsButton;
public:
	Screen();
	~Screen();

	void OnButtonClick(wxCommandEvent& evt);
	void SignButtonClick(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};


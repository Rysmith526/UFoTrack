#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
	bool clicked = false;
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void switchToSearchLocation(wxCommandEvent& evt);
	void switchToSearchDate(wxCommandEvent& evt);
	void switchToReportSighting(wxCommandEvent& evt);
};



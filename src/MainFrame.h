#pragma once
#include <wx/wx.h>
#include "SightingsDatabase.h"

class MainFrame : public wxFrame {
public:
	bool clicked = false;
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings);
	SightingsDatabase sightings;
private:
	void switchToSearchLocation(wxCommandEvent& evt);
	void switchToSearchDate(wxCommandEvent& evt);
	void switchToReportSighting(wxCommandEvent& evt);
};



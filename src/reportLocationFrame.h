#pragma once
#include <wx/wx.h>
#include "SightingsDatabase.h"

class reportLocationFrame : public wxFrame {
public:
	reportLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings);
private:
    SightingsDatabase sightings;
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
};





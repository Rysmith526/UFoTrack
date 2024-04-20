#pragma once
#include <wx/wx.h>
#include "SightingsDatabase.h"
#include "Button.h"
#include "Textbox.h"

class searchLocationFrame : public wxFrame {
public:
	searchLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings);
private:
    SightingsDatabase sightings;
    Button* submitButton;
    TextBox* latitudeBox;
    TextBox* longitudeBox;
    wxArrayString results;
    wxListBox* resultsBox;
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
    void searchSort();
    
};





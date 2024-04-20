#pragma once
#include <wx/wx.h>
#include "SightingsDatabase.h"
#include "Button.h"
#include "Textbox.h"

class searchDateFrame : public wxFrame {
public:
	searchDateFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings);
private:
    SightingsDatabase sightings;
    Button* submitButton;
    TextBox* yearBox;
    wxChoice* monthChoice;
    TextBox* dayBox;
    wxArrayString results;
    wxListBox* resultsBox;
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
    void searchSort();
};





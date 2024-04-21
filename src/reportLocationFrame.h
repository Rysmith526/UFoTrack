#pragma once
#include <wx/wx.h>
#include "SightingsDatabase.h"
#include "Button.h"
#include "Textbox.h"

class reportLocationFrame : public wxFrame {
public:
	reportLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings);
private:
    SightingsDatabase sightings;
    TextBox* latTextbox;
    TextBox* longTextbox;
    TextBox* cityTextbox;
    wxChoice* stateChoice;
    TextBox* yearTextbox;
    wxChoice* monthChoicebox;
    TextBox* dayTextBox;
    TextBox* hourTextBox;
    TextBox* minuteTextBox;
    wxChoice* shapeChoice;
    TextBox* descriptionTextbox;
    TextBox* durationTextbox;
    Button* submitButton;
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
    void insertSighting();
};





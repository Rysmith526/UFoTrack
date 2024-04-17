#pragma once
#include <wx/wx.h>

class searchLocationFrame : public wxFrame {
public:
	searchLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
};





#pragma once
#include <wx/wx.h>

class searchDateFrame : public wxFrame {
public:
	searchDateFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
};





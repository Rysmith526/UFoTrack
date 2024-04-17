#pragma once
#include <wx/wx.h>

class reportLocationFrame : public wxFrame {
public:
	reportLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnButtonClicked(wxCommandEvent& evt);
    void submitButtonClicked(wxCommandEvent& evt);
};





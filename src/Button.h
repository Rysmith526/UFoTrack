#pragma once
#include <wx/wx.h>

class Button : public wxButton {
public:
    Button(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size);
};
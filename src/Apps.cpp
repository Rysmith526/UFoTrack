#include "Apps.h"
#include <wx/wx.h>
#include "SearchLocationFrame.h"
#include "MainFrame.h"
#include "Button.h"
#include "Textbox.h"

bool Apps::OnInit() {
    MainFrame* window1 = new MainFrame(wxString("UFoTrack"), wxPoint(300, 100), wxSize(800, 600));
    window1->Center();
    window1->Show(true);
    //window1->Bind(wxEVT_BUTTON, &window1->OnButtonClicked, window1);
    //SearchLocationFrame* window2 = new SearchLocationFrame(wxString("Window 2"), wxPoint(300, 400), wxSize(200, 150));
    //window2->Show(true);

    
    return true;
}


wxIMPLEMENT_APP(Apps);

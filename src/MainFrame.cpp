#include "MainFrame.h"
#include "SearchLocationFrame.h"
#include "searchDateFrame.h"
#include "reportLocationFrame.h"
#include <wx/wx.h>
#include "Button.h"
#include "Textbox.h"



MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size): wxFrame(nullptr, wxID_ANY, title, pos, size) {
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
   
    wxJPEGHandler *handler = new wxJPEGHandler; 
    wxImage::AddHandler(handler);
    wxPanel* imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    
    //wxBitmap* image = new wxBitmap(imagePanel, wxID_ANY, wxBitmap("Best-ufo-wallpaper.jpg", wxBITMAP_TYPE_JPEG), wxDefaultPosition, wxSize(800, 600));
    //UFoTrack Title
    wxFont titleFont(wxFontInfo(wxSize(0,36)).Bold());
    wxStaticText* title1 = new wxStaticText(mainPanel, wxID_ANY, "UFoTrack", wxPoint(100, 50), wxSize(125, 50));
    title1->SetFont(titleFont);
    //Search by Location Button
    Button* button1 = new Button(mainPanel, wxID_ANY, "Search by Location", wxPoint(80, 300), wxSize(125, 50));
    //Search by Date Button
    Button* button2 = new Button(mainPanel, wxID_ANY, "Search by Date", wxPoint(330, 300), wxSize(125, 50));
    //Report Sighting Button
    Button* button3 = new Button(mainPanel, wxID_ANY, "REPORT SIGHTING", wxPoint(250, 425), wxSize(300, 50));

    
    
    button1->Bind(wxEVT_BUTTON, &MainFrame::switchToSearchLocation, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::switchToSearchDate, this);
    button3->Bind(wxEVT_BUTTON, &MainFrame::switchToReportSighting, this);

   // imagePanel->Raise();
    
    

    
    
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    
}

void MainFrame::switchToSearchLocation(wxCommandEvent& evt) {
    searchLocationFrame* window2 = new searchLocationFrame(wxString("Search by Location"), wxPoint(50, 50), wxSize(800, 600));
    window2->Show(true);
    window2->Center();
    Close();
}

void MainFrame::switchToSearchDate(wxCommandEvent& evt) {
    searchDateFrame* window3 = new searchDateFrame(wxString("Search by Date"), wxPoint(50, 50), wxSize(800, 600));
    window3->Show(true);
    window3->Center();
    Close();
}

void MainFrame::switchToReportSighting(wxCommandEvent& evt) {
    reportLocationFrame* window4 = new reportLocationFrame(wxString("Report Sighting"), wxPoint(50, 50), wxSize(800, 600));
    window4->Show(true);
    window4->Center();
    Close();
}





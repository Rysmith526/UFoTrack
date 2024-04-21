#include "MainFrame.h"
#include "SearchLocationFrame.h"
#include "searchDateFrame.h"
#include "reportLocationFrame.h"
#include <wx/wx.h>
#include "Button.h"
#include "Textbox.h"
#include "SightingsDatabase.h"


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings): wxFrame(nullptr, wxID_ANY, title, pos, size) {
    this->sightings = sightings;
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
   
    wxPNGHandler *handler = new wxPNGHandler; 
    wxImage::AddHandler(handler);
    wxPanel* imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    wxImage image("ufgatorufo.png", wxBITMAP_TYPE_PNG);
    image.Rescale(150, 150);
    wxBitmap imageBitmap(image);
    wxStaticBitmap* imageCtrl = new wxStaticBitmap(this, wxID_ANY, imageBitmap, wxPoint(320, 270), wxDefaultSize);
    
    //UFoTrack Title
    wxFont titleFont(wxFontInfo(wxSize(0,36)).Bold());
    wxStaticText* Utitle1 = new wxStaticText(mainPanel, wxID_ANY, "U", wxPoint(99, 50), wxSize(3, 50));
    wxStaticText* Ftitle1 = new wxStaticText(mainPanel, wxID_ANY, "F", wxPoint(125, 50), wxSize(3, 50));
    wxStaticText* oTracktitle1 = new wxStaticText(mainPanel, wxID_ANY, "oTrack", wxPoint(145, 50), wxSize(80, 50));
    Utitle1->SetFont(titleFont);
    Ftitle1->SetFont(titleFont);
    oTracktitle1->SetFont(titleFont);
    Utitle1->SetForegroundColour(wxColour(0, 33, 165)); 
    Ftitle1->SetForegroundColour(wxColour(250, 70, 22)); 
    oTracktitle1->SetForegroundColour(wxColour(131, 89, 163)); 
    wxStaticText* welcomeText = new wxStaticText(mainPanel, wxID_ANY, "Welcome to UFoTrack, your ultimate tool for exploring and reporting UFO sightings! With a database of 60,000 documented encounters from 1910-2014, UFOTrack offers a variety of features to help you delve into the mysterious world of unidentified flying objects. \n\nUse our GPS coordinate search to discover sightings nearest to a specific location, allowing you to uncover intriguing incidents that may have occurred in your area. Alternatively, explore sightings based on their date, discovering events that coincide with specific moments in time or significant historical events. \n\nAdditionally, UFOTrack provides a platform for you to contribute to our growing database by reporting your own sightings. Share your experiences with the community and contribute to our collective understanding of these enigmatic phenomena.", wxPoint(70, 100), wxSize(600, 175));
    //Search by Location Button
    Button* button1 = new Button(mainPanel, wxID_ANY, "Search by Location", wxPoint(125, 300), wxSize(125, 50));
    //Search by Date Button
    Button* button2 = new Button(mainPanel, wxID_ANY, "Search by Date", wxPoint(550, 300), wxSize(125, 50));
    //Report Sighting Button
    Button* button3 = new Button(mainPanel, wxID_ANY, "REPORT SIGHTING", wxPoint(250, 425), wxSize(300, 50));

    
    
    button1->Bind(wxEVT_BUTTON, &MainFrame::switchToSearchLocation, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::switchToSearchDate, this);
    button3->Bind(wxEVT_BUTTON, &MainFrame::switchToReportSighting, this);

   // imagePanel->Raise();
    
    

    
    
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    
}

void MainFrame::switchToSearchLocation(wxCommandEvent& evt) {
    searchLocationFrame* window2 = new searchLocationFrame(wxString("Search by Location"), wxPoint(50, 50), wxSize(800, 600), this->sightings);
    window2->Show(true);
    window2->Center();
    Close();
}

void MainFrame::switchToSearchDate(wxCommandEvent& evt) {
    searchDateFrame* window3 = new searchDateFrame(wxString("Search by Date"), wxPoint(50, 50), wxSize(800, 600), this->sightings);
    window3->Show(true);
    window3->Center();
    Close();
}

void MainFrame::switchToReportSighting(wxCommandEvent& evt) {
    reportLocationFrame* window4 = new reportLocationFrame(wxString("Report Sighting"), wxPoint(50, 50), wxSize(800, 600), this->sightings);
    window4->Show(true);
    window4->Center();
    Close();
}





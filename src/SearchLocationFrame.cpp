#include "SearchLocationFrame.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include "Button.h"
#include "Textbox.h"
#include "SightingsDatabase.h"


searchLocationFrame::searchLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings): wxFrame(nullptr, wxID_ANY, title, pos, size) {
    this->sightings = sightings;
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
   
    wxJPEGHandler *handler = new wxJPEGHandler; 
    wxImage::AddHandler(handler);
    wxPanel* imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    
    //wxBitmap* image = new wxBitmap(imagePanel, wxID_ANY, wxBitmap("Best-ufo-wallpaper.jpg", wxBITMAP_TYPE_JPEG), wxDefaultPosition, wxSize(800, 600));
    //Year Month Day titles
    wxFont titleFont(wxFontInfo(wxSize(0,20)));
    wxStaticText* title1 = new wxStaticText(mainPanel, wxID_ANY, "Latitude", wxPoint(100, 50), wxSize(50, 20));
    wxStaticText* title2 = new wxStaticText(mainPanel, wxID_ANY, "Longitude", wxPoint(360, 50), wxSize(50, 20));
    //wxStaticText* title3 = new wxStaticText(mainPanel, wxID_ANY, "Day", wxPoint(300, 50), wxSize(50, 20));
    wxStaticText* title4 = new wxStaticText(mainPanel, wxID_ANY, "Results", wxPoint(40, 130), wxSize(50, 20));
    wxStaticText* title5 = new wxStaticText(mainPanel, wxID_ANY, "Sort by?", wxPoint(700, 150), wxSize(50, 20));
    wxStaticText* title6 = new wxStaticText(mainPanel, wxID_ANY, "Time:", wxPoint(700, 220), wxSize(50, 20));

    title1->SetFont(titleFont);
    title2->SetFont(titleFont);
    title5->SetFont(titleFont);
    //title3->SetFont(titleFont);
    //Latitude TextBox
    latitudeBox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(40, 80), wxSize(200, 30), wxTE_LEFT, wxTextValidator(wxFILTER_NUMERIC));
    //Longitude TextBox
    longitudeBox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(300, 80), wxSize(200, 30), wxTE_LEFT, wxTextValidator(wxFILTER_NUMERIC));
    //Back Button
    Button* backButton = new Button(mainPanel, wxID_ANY, "Back", wxPoint(675, 50), wxSize(100, 70));
    //Search Button
    submitButton = new Button(mainPanel, wxID_ANY, "Search", wxPoint(520, 80), wxSize(100, 30));
    //Results Box
    resultsBox = new wxListBox(mainPanel, wxID_ANY, wxPoint(40, 150), wxSize(650, 350), results, wxLB_HSCROLL);
    //Sort choiceBox
    wxArrayString sortChoices;
    sortChoices.Add("Quick Sort");
    sortChoices.Add("Merge Sort");
    sortChoice = new wxChoice(mainPanel, wxID_ANY, wxPoint(700, 180), wxSize(70, 25), sortChoices);
    //Time of sorting
    timeBox = new wxListBox(mainPanel, wxID_ANY, wxPoint(700, 245), wxSize(70, 100));
    
    submitButton->Bind(wxEVT_BUTTON, &searchLocationFrame::submitButtonClicked, this);
    backButton->Bind(wxEVT_BUTTON, &searchLocationFrame::OnButtonClicked, this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
}

void searchLocationFrame::OnButtonClicked(wxCommandEvent& evt) {
    MainFrame* window1 = new MainFrame(wxString("UFoTrack"), wxPoint(50, 50), wxSize(800, 600), sightings);
    window1->Show(true);
    window1->Center();
    Close();
}

void searchLocationFrame::submitButtonClicked(wxCommandEvent& evt) {
    searchSort();
}

void searchLocationFrame::searchSort() {
    string timer;
    resultsBox->Clear();
    double latitude;
    wxString number(latitudeBox->GetValue());
    number.ToDouble(&latitude);
    double longitude;
    wxString number1(longitudeBox->GetValue());
    number1.ToDouble(&longitude);
    if (sortChoice->GetStringSelection().ToStdString() == "Merge Sort") {
        timer = to_string(sightings.mergeSortByLocation(std::make_pair((float)latitude, (float)longitude)));
    }
    else {
        timer = to_string(sightings.quickSortByLocation(std::make_pair((float)latitude, (float)longitude)));
    }
    timeBox->Append(timer + "s");
    for (int i = 0; i < 500; i++) {
        resultsBox->Append(sightings.returnSightings()[i]);
    }
}






#include "searchDateFrame.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include "Button.h"
#include "Textbox.h"


searchDateFrame::searchDateFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
   
    wxJPEGHandler *handler = new wxJPEGHandler; 
    wxImage::AddHandler(handler);
    wxPanel* imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    
    //wxBitmap* image = new wxBitmap(imagePanel, wxID_ANY, wxBitmap("Best-ufo-wallpaper.jpg", wxBITMAP_TYPE_JPEG), wxDefaultPosition, wxSize(800, 600));
    //Year Month Day titles
    wxFont titleFont(wxFontInfo(wxSize(0,20)));
    wxStaticText* title1 = new wxStaticText(mainPanel, wxID_ANY, "Year", wxPoint(100, 50), wxSize(50, 20));
    wxStaticText* title2 = new wxStaticText(mainPanel, wxID_ANY, "Month", wxPoint(200, 50), wxSize(50, 20));
    wxStaticText* title3 = new wxStaticText(mainPanel, wxID_ANY, "Day", wxPoint(300, 50), wxSize(50, 20));
    wxStaticText* title4 = new wxStaticText(mainPanel, wxID_ANY, "Results", wxPoint(40, 130), wxSize(50, 20));
    wxStaticText* title5 = new wxStaticText(mainPanel, wxID_ANY, "Sort by?", wxPoint(700, 150), wxSize(50, 20));
    wxStaticText* title6 = new wxStaticText(mainPanel, wxID_ANY, "Time:", wxPoint(700, 220), wxSize(50, 20));

    title1->SetFont(titleFont);
    title2->SetFont(titleFont);
    title3->SetFont(titleFont);
    title5->SetFont(titleFont);
    //Year TextBox
    TextBox* textbox1 = new TextBox(mainPanel, wxID_ANY, "yyyy", wxPoint(100, 80), wxSize(80, 30));
    //Month TextBox
    wxArrayString monthChoices;
    monthChoices.Add("01");
    monthChoices.Add("02");
    monthChoices.Add("03");
    monthChoices.Add("04");
    monthChoices.Add("05");
    monthChoices.Add("06");
    monthChoices.Add("07");
    monthChoices.Add("08");
    monthChoices.Add("09");
    monthChoices.Add("10");
    monthChoices.Add("11");
    monthChoices.Add("12");
    wxChoice* textbox2 = new wxChoice(mainPanel, wxID_ANY, wxPoint(200, 80), wxSize(80, 30), monthChoices);
    //Day TextBox
    TextBox* textbox3 = new TextBox(mainPanel, wxID_ANY, "dd", wxPoint(300, 80), wxSize(80, 30));
    //Back Button
    Button* backButton = new Button(mainPanel, wxID_ANY, "Back", wxPoint(650, 50), wxSize(100, 70));
    //Search Button
    Button* submitButton = new Button(mainPanel, wxID_ANY, "Search", wxPoint(400, 80), wxSize(100, 30));
    //Results Box
    wxListBox* resultsBox = new wxListBox(mainPanel, wxID_ANY, wxPoint(40, 150), wxSize(650, 350));

    //Sort choiceBox
    wxArrayString sortChoices;
    sortChoices.Add("Quick Sort");
    sortChoices.Add("Merge Sort");
    wxChoice* sortChoice = new wxChoice(mainPanel, wxID_ANY, wxPoint(700, 180), wxSize(70, 25), sortChoices);
    //Time of sorting
    wxListBox* timeBox = new wxListBox(mainPanel, wxID_ANY, wxPoint(700, 245), wxSize(70, 25));
    
    backButton->Bind(wxEVT_BUTTON, &searchDateFrame::OnButtonClicked, this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
}

void searchDateFrame::OnButtonClicked(wxCommandEvent& evt) {
    MainFrame* window1 = new MainFrame(wxString("UFoTrack"), wxPoint(50, 50), wxSize(800, 600));
    window1->Show(true);
    window1->Center();
    Close();
}

void searchDateFrame::submitButtonClicked(wxCommandEvent& evt) {

}





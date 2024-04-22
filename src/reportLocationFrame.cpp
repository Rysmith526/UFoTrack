#include "reportLocationFrame.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include "Button.h"
#include "Textbox.h"
#include "SightingsDatabase.h"
#include <chrono>
#include <ctime>


reportLocationFrame::reportLocationFrame(const wxString& title, const wxPoint& pos, const wxSize& size, SightingsDatabase sightings) : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    this->sightings = sightings;
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
   
    wxJPEGHandler *handler = new wxJPEGHandler; 
    wxImage::AddHandler(handler);
    wxPanel* imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    
    //wxBitmap* image = new wxBitmap(imagePanel, wxID_ANY, wxBitmap("Best-ufo-wallpaper.jpg", wxBITMAP_TYPE_JPEG), wxDefaultPosition, wxSize(800, 600));
    //Where When Shape titles
    wxFont titleFont(wxFontInfo(wxSize(0,20)));
    wxStaticText* title1 = new wxStaticText(mainPanel, wxID_ANY, "Where?", wxPoint(80, 50), wxSize(50, 20));
    wxStaticText* title2 = new wxStaticText(mainPanel, wxID_ANY, "When?", wxPoint(80, 250), wxSize(50, 20));
    wxStaticText* title3 = new wxStaticText(mainPanel, wxID_ANY, "Shape?", wxPoint(80, 440), wxSize(50, 20));
    //wxStaticText* title4 = new wxStaticText(mainPanel, wxID_ANY, "Results", wxPoint(40, 130), wxSize(50, 20));
    title1->SetFont(titleFont);
    title2->SetFont(titleFont);
    title3->SetFont(titleFont);
    //Latitude Textbox
    wxStaticText* latTitle = new wxStaticText(mainPanel, wxID_ANY, "Latitude", wxPoint(70, 80), wxSize(50, 20));
    latTextbox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(40, 100), wxSize(100, 30),wxTE_LEFT, wxTextValidator(wxFILTER_NUMERIC));

    //Longitude TextBox
    wxStaticText* longTitle = new wxStaticText(mainPanel, wxID_ANY, "Longitude", wxPoint(220, 80), wxSize(70, 20));
    longTextbox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(200, 100), wxSize(100, 30), wxTE_LEFT, wxTextValidator(wxFILTER_NUMERIC));
    //City Textbox
    wxStaticText* cityTitle = new wxStaticText(mainPanel, wxID_ANY, "City", wxPoint(70, 140), wxSize(50, 20));
    cityTextbox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(40, 160), wxSize(100, 30));

    //State Choicebox
    wxStaticText* stateTitle = new wxStaticText(mainPanel, wxID_ANY, "State", wxPoint(220, 140), wxSize(70, 20));
    wxArrayString stateChoices;
    stateChoices.Add("AL");
    stateChoices.Add("AK");
    stateChoices.Add("AZ");
    stateChoices.Add("AR");
    stateChoices.Add("CA");
    stateChoices.Add("CO");
    stateChoices.Add("CT");
    stateChoices.Add("DE");
    stateChoices.Add("FL");
    stateChoices.Add("GA");
    stateChoices.Add("HI");
    stateChoices.Add("ID");
    stateChoices.Add("IL");
    stateChoices.Add("IN");
    stateChoices.Add("IA");
    stateChoices.Add("KS");
    stateChoices.Add("KY");
    stateChoices.Add("LA");
    stateChoices.Add("ME");
    stateChoices.Add("MD");
    stateChoices.Add("MA");
    stateChoices.Add("MI");
    stateChoices.Add("MN");
    stateChoices.Add("MS");
    stateChoices.Add("MO");
    stateChoices.Add("MT");
    stateChoices.Add("NE");
    stateChoices.Add("NV");
    stateChoices.Add("NH");
    stateChoices.Add("NJ");
    stateChoices.Add("NM");
    stateChoices.Add("NY");
    stateChoices.Add("NC");
    stateChoices.Add("ND");
    stateChoices.Add("OH");
    stateChoices.Add("OK");
    stateChoices.Add("OR");
    stateChoices.Add("PA");
    stateChoices.Add("RI");
    stateChoices.Add("SC");
    stateChoices.Add("SD");
    stateChoices.Add("TN");
    stateChoices.Add("TX");
    stateChoices.Add("UT");
    stateChoices.Add("VT");
    stateChoices.Add("VA");
    stateChoices.Add("WA");
    stateChoices.Add("WV");
    stateChoices.Add("WI");
    stateChoices.Add("WY");

    stateChoice= new wxChoice(mainPanel, wxID_ANY, wxPoint(200, 160), wxSize(100, 30), stateChoices);
    

    //Year TextBox
    wxStaticText* year_title = new wxStaticText(mainPanel, wxID_ANY, "Year?", wxPoint(85, 230+50), wxSize(40, 18));
    yearTextbox = new TextBox(mainPanel, wxID_ANY, "yyyy", wxPoint(80, 250+50), wxSize(40, 25));
    //Month TextBox
    wxStaticText* month_title = new wxStaticText(mainPanel, wxID_ANY, "Month?", wxPoint(140, 230+50), wxSize(50, 18));
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
    monthChoicebox = new wxChoice(mainPanel, wxID_ANY, wxPoint(140, 250+50), wxSize(40, 25), monthChoices);
    //Day TextBox
    wxStaticText* day_title = new wxStaticText(mainPanel, wxID_ANY, "Day?", wxPoint(200, 230+50), wxSize(50, 18));
    dayTextBox = new TextBox(mainPanel, wxID_ANY, "dd", wxPoint(195, 250+50), wxSize(40, 25));
    //Hour Textbox
    wxStaticText* hour_title = new wxStaticText(mainPanel, wxID_ANY, "Hour?", wxPoint(105, 290+50), wxSize(50, 18));
    hourTextBox = new TextBox(mainPanel, wxID_ANY, "hh", wxPoint(100, 305+50), wxSize(40, 25));
    //Minute Textbox
    wxStaticText* minute_title = new wxStaticText(mainPanel, wxID_ANY, "Minute?", wxPoint(162, 290+50), wxSize(50, 18));
    minuteTextBox = new TextBox(mainPanel, wxID_ANY, "mm", wxPoint(160, 305+50), wxSize(40, 25));
    //Shape Choicebox
    wxArrayString shapeChoices;
    shapeChoices.Add("Changing");
    shapeChoices.Add("Chevron");
    shapeChoices.Add("Cigar");
    shapeChoices.Add("Circle");
    shapeChoices.Add("Cone");
    shapeChoices.Add("Cross");
    shapeChoices.Add("Cube");
    shapeChoices.Add("Cylinder");
    shapeChoices.Add("Diamond");
    shapeChoices.Add("Disk");
    shapeChoices.Add("Egg");
    shapeChoices.Add("Fireball");
    shapeChoices.Add("Flash");
    shapeChoices.Add("Formation");
    shapeChoices.Add("Light");
    shapeChoices.Add("Orb");
    shapeChoices.Add("Other");
    shapeChoices.Add("Oval");
    shapeChoices.Add("Rectangle");
    shapeChoices.Add("Sphere");
    shapeChoices.Add("Star");
    shapeChoices.Add("Teardrop");
    shapeChoices.Add("Triangle");
    shapeChoices.Add("Unknown");
    shapeChoice = new wxChoice(mainPanel, wxID_ANY, wxPoint(75, 470), wxSize(70, 25), shapeChoices);
    //Back Button
    Button* backButton = new Button(mainPanel, wxID_ANY, "Back", wxPoint(650, 50), wxSize(100, 70));
    //Search Button
    submitButton = new Button(mainPanel, wxID_ANY, "Submit", wxPoint(400, 80), wxSize(100, 30));
    //Results Box
    //wxListBox* resultsBox = new wxListBox(mainPanel, wxID_ANY, wxPoint(40, 150), wxSize(650, 350));
    wxStaticText* descriptionTitle = new wxStaticText(mainPanel, wxID_ANY, "Write your description!", wxPoint(380, 180), wxSize(130, 18));
    descriptionTextbox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(380, 200), wxSize(350, 300), wxTE_MULTILINE);

    wxStaticText* durationTitle = new wxStaticText(mainPanel, wxID_ANY, "Duration? (miliseconds)", wxPoint(250, 330), wxSize(130, 18));
    durationTextbox = new TextBox(mainPanel, wxID_ANY, "", wxPoint(300, 350), wxSize(40, 25), wxTE_LEFT, wxTextValidator(wxFILTER_NUMERIC));
    
    submitButton->Bind(wxEVT_BUTTON, &reportLocationFrame::submitButtonClicked, this);
    backButton->Bind(wxEVT_BUTTON, &reportLocationFrame::OnButtonClicked, this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
}

void reportLocationFrame::OnButtonClicked(wxCommandEvent& evt) {
    MainFrame* window1 = new MainFrame(wxString("UFoTrack"), wxPoint(50, 50), wxSize(800, 600), this->sightings);
    window1->Show(true);
    window1->Center();
    Close();
}

void reportLocationFrame::submitButtonClicked(wxCommandEvent& evt) {
    insertSighting();
}
void reportLocationFrame::insertSighting() {
    double latitude;
    wxString number(latTextbox->GetValue());
    number.ToDouble(&latitude);
    double longitude;
    wxString number1(longTextbox->GetValue());
    number1.ToDouble(&longitude);
    
    string city = cityTextbox->GetValue().ToStdString();
    string state = stateChoice->GetStringSelection().ToStdString();

    int year = std::stoi(yearTextbox->GetValue().ToStdString());
    int month = std::stoi(monthChoicebox->GetStringSelection().ToStdString());
    int day = std::stoi(dayTextBox->GetValue().ToStdString());
    int hour = std::stoi(hourTextBox->GetValue().ToStdString());
    int minute = std::stoi(minuteTextBox->GetValue().ToStdString());

    auto currentTime = std::chrono::system_clock::now();
    time_t time_now = std::chrono::system_clock::to_time_t(currentTime);

    struct tm* local_time = std::localtime(&time_now);

    int currentYear = local_time->tm_year + 1900; 
    int currentMonth = local_time->tm_mon + 1;    
    int currentDay = local_time->tm_mday;         

    string shape = shapeChoice->GetStringSelection().ToStdString();

    string description = descriptionTextbox->GetValue().ToStdString();
    int duration = std::stoi(durationTextbox->GetValue().ToStdString());

    vector<std::string> strParams = {city, state, "US", shape, description};
    vector<int> intParams = {duration, year, month, day, hour, minute, currentYear, currentMonth, currentDay};
    std::pair<float, float> coords = std::make_pair((float)latitude, (float)longitude);

    sightings.insertSighting(strParams, coords, intParams);

    latTextbox->Clear();
    longTextbox->Clear();
    cityTextbox->Clear();
    yearTextbox->Clear();
    monthChoicebox->Clear();
    dayTextBox->Clear();
    minuteTextBox->Clear();
    descriptionTextbox->Clear();
    shapeChoice->Clear();
    monthChoicebox->Clear();

}






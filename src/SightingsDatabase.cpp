#include "SightingsDatabase.h"

SightingsDatabase::Sighting::Date::Date()
{
    this->year = 1901;
    this->month = 1;
    this->day = 1;
}

SightingsDatabase::Sighting::Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

//Returns MM/DD/YYYY
string SightingsDatabase::Sighting::Date::dateString()
{
    string returnDate = "";
    string monthStr = to_string(month);
    string dayStr = to_string(day);
    string yearStr = to_string(year);
    if (monthStr.length() == 1)
        returnDate += "0";
    returnDate += monthStr + "/";
    if (dayStr.length() == 1)
        returnDate += "0";
    returnDate += dayStr + "/" + yearStr;
    return returnDate;

}

int SightingsDatabase::Sighting::Date::getYear()
{
    return year;
}

int SightingsDatabase::Sighting::Date::getMonth()
{
    return month;
}

int SightingsDatabase::Sighting::Date::getDay()
{
    return day;
}

SightingsDatabase::Sighting::SightingDate::SightingDate() {
    this->year = 1901;
    this->month = 1;
    this->day = 1;
    this->hour = 0;
    this->minute = 0;
}

SightingsDatabase::Sighting::SightingDate::SightingDate(int year, int month, int day, int hour, int minutes)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minutes;
}

//Returns HH:MM, MM/DD/YYYY
string SightingsDatabase::Sighting::SightingDate::getDate()
{
    string timeStr = "";
    string hourStr = to_string(hour);
    string minStr = to_string(minute);
    if (hourStr.length() == 1)
        timeStr += "0";
    timeStr += hourStr + ":";
    if (minStr.length() == 1)
        timeStr += "0";
    timeStr += minStr;
    return timeStr + ", " + dateString();
}

int SightingsDatabase::Sighting::SightingDate::getHour()
{
    return hour;
}

int SightingsDatabase::Sighting::SightingDate::getMinute()
{
    return minute;
}

//Returns minutes since 12:00 AM, 1/1/1901 (check logic)
int SightingsDatabase::Sighting::SightingDate::minutesSince1901()
{
    int totalMinutes = 0;
    int yearsSince1901 = year - 1901;
    totalMinutes += (1461 * 24 * 60) * (yearsSince1901 / 4);
    totalMinutes += (365 * 24 * 60) * (yearsSince1901 % 4);
    if (month == 2)
    {
        totalMinutes += 31 * 24 * 60;
    }
    else
    {
        //To account for leap year
        if (yearsSince1901 % 4 == 3)
            totalMinutes += 24 * 60;
        if (month == 3)
        {
            totalMinutes += 59 * 24 * 60;
        }
        else if (month == 4)
        {
            totalMinutes += 90 * 24 * 60;
        }
        else if (month == 5)
        {
            totalMinutes += 120 * 24 * 60;
        }
        else if (month == 6)
        {
            totalMinutes += 151 * 24 * 60;
        }
        else if (month == 7)
        {
            totalMinutes += 181 * 24 * 60;
        }
        else if (month == 8)
        {
            totalMinutes += 212 * 24 * 60;
        }
        else if (month == 9)
        {
            totalMinutes += 243 * 24 * 60;
        }
        else if (month == 10)
        {
            totalMinutes += 273 * 24 * 60;
        }
        else if (month == 11)
        {
            totalMinutes += 304 * 24 * 60;
        }
        else if (month == 12)
        {
            totalMinutes += 334 * 24 * 60;
        }
    }
    totalMinutes += (day - 1) * 24 * 60;
    totalMinutes += hour * 60 + minute;
    return totalMinutes;
}

SightingsDatabase::Sighting::DocumentedDate::DocumentedDate() {

}

string SightingsDatabase::Sighting::DocumentedDate::getDate()
{
    return dateString();
}

SightingsDatabase::Sighting::Sighting()
{
    this->locationCity = "Gainesville";
    this->locationState = "FL";
    this->locationCountry = "USA";
    this->shape = "disc";
    this->duration = 5;
    this->description = "aliens!";
    this->coordinates = make_pair(29.6513889, -82.325);
    this->sightDate = SightingDate(1901, 1, 1, 0, 0);
    this->docDate = DocumentedDate(1901, 1, 1);
}

//Str Params: City, State, Country, Shape, Description; Int Params: Sighting Year, Month, Day, Hour, Minutes, Doc. Year, Month, Day
SightingsDatabase::Sighting::Sighting(vector<string>& strParams, pair<float, float> coordinates, vector<int>& intParams)
{
    this->locationCity = strParams[0];
    this->locationState = strParams[1];
    this->locationCountry = strParams[2];
    this->shape = strParams[3];
    this->duration = intParams[0];
    this->description = strParams[4];
    this->coordinates = coordinates;
    this->sightDate = SightingDate(intParams[1], intParams[2], intParams[3], intParams[4], intParams[5]);
    this->docDate = DocumentedDate(intParams[6], intParams[7], intParams[8]);
}

//May need a larger data type than int 
void SightingsDatabase::Sighting::setDifferenceByDate(int year, int month, int day, int hour, int minutes)
{
    SightingDate inputDate = SightingDate(year, month, day, hour, minutes);
    difference = abs(sightDate.minutesSince1901() - inputDate.minutesSince1901());
}

void SightingsDatabase::Sighting::setDifferenceByLocation(pair<float, float> inputCoordinates)
{
    float xdiff = coordinates.first - inputCoordinates.first;
    float ydiff = coordinates.second - inputCoordinates.second;
    difference = sqrt(pow(xdiff, 2) + pow(ydiff, 2));
}

void SightingsDatabase::Sighting::setDifference(int difference)
{
    this->difference = difference;
}

int SightingsDatabase::Sighting::getDifference()
{
    return difference;
}

std::string SightingsDatabase::Sighting::getLocationCity()  { return locationCity; }
std::string SightingsDatabase::Sighting::getLocationState()  { return locationState; }
std::string SightingsDatabase::Sighting::getLocationCountry()  { return locationCountry; }
std::string SightingsDatabase::Sighting::getShape()  { return shape; }
int SightingsDatabase::Sighting::getDuration()  { return duration; }
std::string SightingsDatabase::Sighting::getDescription()  { return description; }
std::pair<float, float> SightingsDatabase::Sighting::getCoordinates()  { return coordinates; }
string SightingsDatabase::Sighting::getSightDate()  { return sightDate.getDate(); }
string SightingsDatabase::Sighting::getDocDate()  { return docDate.getDate(); }

//Sorting Lecture was referenced
void SightingsDatabase::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

//Sorting Lecture was referenced
void SightingsDatabase::merge(int left, int mid, int right)
{
    queue<Sighting> leftQueue;
    queue<Sighting> rightQueue;
    for (int i = left; i < mid + 1; i++)
        leftQueue.push(sightings[i]);
    for (int j = mid + 1; j < right + 1; j++)
        rightQueue.push(sightings[j]);
    
    int k = left;
    while(leftQueue.size() > 0 && rightQueue.size() > 0)
    {
        if (leftQueue.front().getDifference() <= rightQueue.front().getDifference())
        {
            sightings[k] = leftQueue.front();
            leftQueue.pop();
        }
        else
        {
            sightings[k] = rightQueue.front();
            rightQueue.pop();
        }
        k++;
    }
    while (leftQueue.size() > 0)
    {
        sightings[k] = leftQueue.front();
        leftQueue.pop();
        k++;
    }
    while (rightQueue.size() > 0)
    {
        sightings[k] = rightQueue.front();
        rightQueue.pop();
        k++;
    }

}

// https://www.geeksforgeeks.org/csv-file-management-using-c/ was referenced
// May need to add input verification from file
SightingsDatabase::SightingsDatabase() {
    vector<Sighting> sightingg;
    this->sightings = sightingg;
    //void insertSighting(vector<string>& strParams, pair<float, float> coordinates, vector<int>& intParams);
    //Str Params: City, State, Country, Shape, Description; Int Params: Sighting Year, Month, Day, Hour, Minutes, Doc. Year, Month, Day
    vector<std::string> strParams = {"Gainesville", "FL", "USA", "disc", "aliens!"};
    vector<int> intParams = {1, 1901, 1, 1, 0, 0, 1901, 1, 1};
    pair<float, float> coords = make_pair(29.6513889, -82.325);
    
    insertSighting(strParams, coords, intParams);
}

SightingsDatabase::SightingsDatabase(string filename)
{
    fstream fin;
    fin.open(filename, ios::in);

    vector<string> row;
    string line, word, temp;
    vector<string> strParams;
    vector<int> intParams;

    bool firstLine = true;

    while (getline(fin, line))
    {
        row.clear();
        strParams.clear();
        intParams.clear();
        stringstream s(line);
        cout << line << endl;
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (!firstLine)
        {
            strParams.push_back(row[0]);
            strParams.push_back(row[1]);
            strParams.push_back(row[2]);
            strParams.push_back(row[3]);
            intParams.push_back(stoi(row[4]));
            strParams.push_back(row[5]);
            intParams.push_back(stoi(row[8]));
            intParams.push_back(stoi(row[9]));
            intParams.push_back(stoi(row[10]));
            intParams.push_back(stoi(row[11]));
            intParams.push_back(stoi(row[12]));
            intParams.push_back(stoi(row[13]));
            intParams.push_back(stoi(row[14]));
            intParams.push_back(stoi(row[15]));
            sightings.push_back(Sighting(strParams, make_pair(stof(row[6]), stof(row[7])), intParams));
        }
        else
            firstLine = false;
    }
}

//Maybe add writing to csv file
//Str Params: City, State, Country, Shape, Description; Int Params: Sighting Year, Month, Day, Hour, Minutes, Doc. Year, Month, Day
void SightingsDatabase::insertSighting(vector<string>& strParams, pair<float, float> coordinates, vector<int>& intParams)
{
    sightings.push_back(Sighting(strParams, coordinates, intParams));
}

void SightingsDatabase::mergeSortByDate(int year, int month, int day, int hour, int minutes)
{
    for (Sighting sighting : sightings)
        sighting.setDifferenceByDate(year, month, day, hour, minutes);
    mergeSort(0, sightings.size() - 1);
}

void SightingsDatabase::mergeSortByLocation(pair<float, float> inputCoordinates)
{
    for (Sighting sighting : sightings)
        sighting.setDifferenceByLocation(inputCoordinates);
    mergeSort(0, sightings.size() - 1);
}

//Needs to be implemented
void SightingsDatabase::quickSortByDate(int year, int month, int day, int hour, int minutes)
{
    for (Sighting sighting : sightings)
        sighting.setDifferenceByDate(year, month, day, hour, minutes);
}

//Needs to be implemented
void SightingsDatabase::quickSortByLocation(pair<float, float> inputCoordinates)
{
    for (Sighting sighting : sightings)
        sighting.setDifferenceByLocation(inputCoordinates);
}

vector<std::string> SightingsDatabase::returnSightings() {
    vector<std::string> vectorOfSightings;
    for (Sighting sighting : sightings) {
        std::string info;

        info += "City: " + sighting.getLocationCity() + ", ";
        info += "State: " + sighting.getLocationState() + ", ";
        info += "Country: " + sighting.getLocationCountry() + ", ";
        info += "Shape: " + sighting.getShape() + ", ";
        info += "Duration: " + std::to_string(sighting.getDuration()) + ", ";
        info += "Description: " + sighting.getDescription() + ", ";

        info += "Coordinates: (" + std::to_string(sighting.getCoordinates().first) + ", " + std::to_string(sighting.getCoordinates().second) + "), ";

        info += "Sighting Date: " + sighting.getSightDate() + ", ";
        info += "Documented Date: " + sighting.getDocDate() + ", ";

        info.pop_back();
        info.pop_back();
        vectorOfSightings.push_back(info);
    }
    return vectorOfSightings;
    
}


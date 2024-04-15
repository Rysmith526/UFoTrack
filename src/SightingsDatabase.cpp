#include "SightingsDatabase.h"

//Needs to be completed
SightingsDatabase::Sighting::Date::Date()
{
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

SightingsDatabase::Sighting::SightingDate::SightingDate(int year, int month, int day, int hour, int minutes)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
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

string SightingsDatabase::Sighting::DocumentedDate::getDate()
{
    return dateString();
}

//Needs to be implemented
SightingsDatabase::Sighting::Sighting()
{
}

//Str Params: City, State, Country, Shape, Description; Int Params: Sighting Year, Month, Day, Hour, Minutes, Doc. Year, Month, Day
SightingsDatabase::Sighting::Sighting(vector<string> strParams, pair<float, float> coordinates, vector<int> intParams)
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

//Check logic and math, differences in months not accounted for (may not matter). Look into standard library date representations or other alternatives
//May need a larger data type than int 
void SightingsDatabase::Sighting::setDifferenceByDate(int year, int month, int day, int hour, int minutes)
{
    int totalMinutes;
    totalMinutes += abs(minutes - sightDate.getMinute());
    totalMinutes += 60 * abs(hour - sightDate.getHour());
    totalMinutes += 24 * 60 * abs(day - sightDate.getHour());
    totalMinutes += 30 * 24 * 60 * abs(month - sightDate.getMonth());
    totalMinutes += 365 * 30 * 24 * 60 * abs(year - sightDate.getYear());
    difference = totalMinutes;
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

// Needs to be implemented
SightingsDatabase::SightingsDatabase(string filename)
{
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

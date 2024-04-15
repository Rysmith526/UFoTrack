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

//Needs to be completed
SightingsDatabase::Sighting::SightingDate::SightingDate()
{

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

string SightingsDatabase::Sighting::DocumentedDate::getDate()
{
    return dateString();
}

#pragma once

#ifndef SIGHTINGSDATABASE_H
#define SIGHTINGSDATABASE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

class SightingsDatabase
{
	class Sighting
	{
	protected:

        class Date
        {
        protected:
            int year;
            int month;
            int day;

        public:
            Date();
            Date(int year, int month, int day);
            string dateString();
            int getYear();
            int getMonth();
            int getDay();
        };

        class SightingDate : public Date
        {
        protected:
            int hour;
            int minute;

        public:
            using Date::Date; //Allows default constructor to be inherited https://stackoverflow.com/questions/347358/inheriting-constructors
            SightingDate();
            SightingDate(int year, int month, int day, int hour, int minutes);
            string getDate();
            int getHour();
            int getMinute();
            int minutesSince1901();
        };

        class DocumentedDate : public Date
        {
        public:
            using Date::Date; //Allows Constructors to be inherited https://stackoverflow.com/questions/347358/inheriting-constructors
            DocumentedDate();
            string getDate();
        };

	public:
        string locationCity;
        string locationState;
        string locationCountry;
        string shape;
        int duration;
        string description;
        pair<float, float> coordinates; //latitude, longitude
        SightingDate sightDate;
        DocumentedDate docDate;
        float difference; //for use in sorting, will be used for both date sorting and location sorting
        Sighting();
        Sighting(vector<string>& strParams, pair<float, float> coordinates, vector<int>& intParams);
        void setDifferenceByDate(int year, int month, int day, int hour, int minutes);
        void setDifferenceByLocation(pair<float, float> inputCoordinates);
        void setDifference(float difference);
        float getDifference();
        std::string getLocationCity();
        std::string getLocationState();
        std::string getLocationCountry();
        std::string getShape();
        int getDuration();
        std::string getDescription();
        std::pair<float, float> getCoordinates();
        string getSightDate();
        string getDocDate();
	};

    void setDifference(float difference);
    float getDifference();
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void quickSort(int low, int high);
    int partition(int low, int high);

public:
    vector<Sighting> sightings;
    SightingsDatabase();
    SightingsDatabase(string filename);
    void insertSighting(vector<string>& strParams, pair<float, float> coordinates, vector<int>& intParams);
    float mergeSortByDate(int year, int month, int day, int hour, int minutes);
    float mergeSortByLocation(pair<float, float> inputCoordinates);
    float quickSortByDate(int year, int month, int day, int hour, int minutes);
    float quickSortByLocation(pair<float, float> inputCoordinates);
    vector<std::string> returnSightings();
};

#endif

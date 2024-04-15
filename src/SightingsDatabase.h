#pragma once

#ifndef SIGHTINGSDATABASE_H
#define SIGHTINGSDATABASE_H

#include <iostream>
#include <vector>

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
        };

        class SightingDate : public Date
        {
        protected:
            int hour;
            int minute;

        public:
            SightingDate();
            SightingDate(int year, int month, int day, int hour, int minutes);
            string getDate();
        };

        class DocumentedDate : public Date
        {
        public:
            string getDate();
        };

        string locationCity;
        string locationState;
        string locationCountry;
        string shape;
        int duration;
        string description;
        pair<float, float> coordinates; //latitude, longitude
        SightingDate sightDate;
        DocumentedDate docDate;


	public:
    

 
	};

	vector<Sighting> sightings;



public:

    SightingsDatabase(string filename);
};

#endif
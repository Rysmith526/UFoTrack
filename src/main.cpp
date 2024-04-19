#include <iostream>
#include <iomanip>
#include <regex>
#include "SightingsDatabase.h"

using namespace std;

int main()
{
    SightingsDatabase db = SightingsDatabase("ufo_sightings.csv");
    db.mergeSortByLocation(make_pair(57.5033333, -134.5838889));
    for (int i = 0; i < 100; i++)
    {
        cout << db.sightings[i].locationCity << endl;
        cout << db.sightings[i].difference << endl;
    }
}
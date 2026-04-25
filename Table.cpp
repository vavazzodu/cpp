#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

typedef struct city
{
    string name;
    long population;
    double rate;
}city_t;
typedef struct country
{
    string name;
    vector <city_t> cities;
}country_t;
typedef struct tours
{
    string title;
    vector <country_t> countries;
}tours_t;

int main()
{
    bool lvDoShift = false;
    cout << setprecision(2) << fixed;
    tours_t MyTours = 
        {
            "Karan's tours",
            {
                {
                    "India",
                    {
                        {
                            "Bangalore",
                            184000,
                            400.85
                        },
                        {
                            "Bombay",
                            284000,
                            415.123
                        },
                        {
                            "Delhi",
                            84000,
                            132.875
                        }
                    },
                },
                {
                    "Pakistan",
                    {
                        {
                            "Karachi",
                            105000,
                            200.85
                        },
                        {
                            "Islamabad",
                            94000,
                            223.123
                        },
                        {
                            "Rawalpindi",
                            64000,
                            540.8
                        }
                    },
                },
                {
                    "United States",
                    {
                        {
                            "Texas",
                            244000,
                            600.85
                        },
                        {
                            "New York",
                            344000,
                            205.123
                        },
                        {
                            "Chicago",
                            84000,
                            154.875
                        }
                    },
                },
            }
        };
    cout <<"12345678901234567890123456789012345678901234567890"<<endl;
    cout <<"--------------------------------------------------"<< endl;
    cout << setw(30) << right << MyTours.title << endl;
    cout <<"--------------------------------------------------"<< endl;
    cout <<setw(15) <<left<< "Country" << setw(15) << left << "City"
         <<setw(15) <<left<< "Population" << setw(15) << left << "Rate" << endl;
    cout <<"--------------------------------------------------"<< endl;
    for ( auto lvCountry : MyTours.countries )
    {
        lvDoShift = false;
        cout << setw(15) << left << lvCountry.name ;
        for ( auto lvCities : lvCountry.cities )
        {
            if ( lvDoShift == true )
            {
                cout <<"               ";
                cout << setw(10) << left << lvCities.name;
                cout << setw(15) << right << lvCities.population;
                cout << setw(10) << right << lvCities.rate << endl;
            }
            else
            {
                cout << setw(10) << left << lvCities.name;
                cout << setw(15) << right << lvCities.population;
                cout << setw(10) << right << lvCities.rate << endl;
                lvDoShift = true;
            }
        }
    }
    return 0;
}
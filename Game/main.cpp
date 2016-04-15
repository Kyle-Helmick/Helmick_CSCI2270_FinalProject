#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Timer.h"
#include "Printing.h"

using namespace std;

int main()
{
    Timer timer;
    Printing printing;
    string welcome_m = "Welcome to [insert name here]!"; //welcome message
    printing.TextPrint(welcome_m);
    cout << endl;

    string cities; //for cin
    string cities_m = "Please input the amount of cities you would play against (4-16): "; //cities amount message
    printing.TextPrint(cities_m);
    cin >> cities;

    int cities_a; //cities amount
    cities_a = atoi(cities.c_str());

    while((cities_a < 4) || (cities_a > 16))
    {
        string bounds_m = "Sorry out of bounds: "; //out of bounds message
        printing.TextPrint(bounds_m);
        cin >> cities;
        cities_a = atoi(cities.c_str());
    }
    cout << "Ready!" << endl;
    timer.wait(2);



}

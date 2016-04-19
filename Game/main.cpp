#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Timer.h"
#include "Printing.h"
#include "Graph.h"
#include <vector>

using namespace std;

int main()
{
    Timer timer;
    Printing printing;
    Graph graph;

    string welcome_m = "Welcome to [insert game name here]!"; //welcome message
    printing.TextPrint(welcome_m);
    cout << endl;

    string name_m = "Please input your cities name: ";
    printing.TextPrint(name_m);
    string user_name;
    getline(cin, user_name);

    string cities; //for cin
    string cities_m = "Please input the amount of cities you would play against (3-15): "; //cities amount message
    printing.TextPrint(cities_m);
    cin >> cities;

    int cities_a; //cities amount
    cities_a = atoi(cities.c_str());
    while((cities_a < 3) || (cities_a > 15))
    {
        string bounds_m = "Sorry out of bounds: "; //out of bounds message
        printing.TextPrint(bounds_m);
        cin >> cities;
        cities_a = atoi(cities.c_str());
    }
    cout << "Ready!" << endl;

    vector <string> city_names;
    city_names.push_back(user_name);
    for(int i = 0; i < cities_a; i++)
    {
        char ins = 'A' + i;
        string ins2 = string(1, ins);
        string ins3 = "City: " + ins2;
        city_names.push_back(ins3);
    }

    for(int i = 0; i < city_names.size(); i++)
    {
        graph.addVertex(city_names[i]);
    }
    graph.addEdge();
    graph.print();
}

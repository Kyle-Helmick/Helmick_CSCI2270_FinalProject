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

    string user_name,mm,cities,action_menu;
    int main_menu = 1,cities_a;
    vector <string> city_names;
    bool play = true;

    printing.NewPage();
    printing.MainMenu();
    getline(cin, mm);

    while(main_menu != -1)
    {
        if(mm == "P")
        {
            string name_m = "Please input your cities name: ";
            printing.TextPrint(name_m);
            getline(cin, user_name);
            if((user_name == "Back") || (user_name == "back"))
            {
                printing.NewPage();
                cout << "ERROR: You cannot name your city 'Back'" << endl;
                printing.MainMenu();
            }
            else
            {
                break;
            }
        }
        else if(mm == "Q")
        {
            cout << "Goodbye!" << endl;
            main_menu = -1;
            break;
        }
        else
        {
            printing.NewPage();
            cout << "ERROR: Please input either P or Q!" << endl;
            printing.MainMenu();
            getline(cin, mm);
        }
    }
    if(main_menu != -1)
    {
        string cities_m = "Please input the amount of cities you would play against (3-15): "; //cities amount message
        printing.TextPrint(cities_m);
        getline(cin, cities);
        cities_a = atoi(cities.c_str());

        while((cities_a < 3) || (cities_a > 15))
        {
            string bounds_m = "Sorry out of bounds: "; //out of bounds message
            printing.TextPrint(bounds_m);
            getline(cin, cities);
            cities_a = atoi(cities.c_str());
        }
        cout << "Ready!" << endl;

        printing.NewPage();

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

        while (play = true)
        {
            printing.ActionMenu();
            getline(cin, action_menu);
            if(action_menu == "A")
            {

            }
            else if(action_menu == "F")
            {

            }
            else if(action_menu == "W")
            {

            }
            else if((action_menu == "Back") || (action_menu == "back"))
            {

            }
            else
            {

            }

        }
    }
}

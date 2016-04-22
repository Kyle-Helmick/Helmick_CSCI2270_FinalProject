#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Printing.h"
#include "Graph.h"
#include <vector>

using namespace std;

int main()
{
    Printing printing;
    Graph graph;

    string user_name,mm,cities,action_menu,att_ch1,att_ch2,def_ch,res_ch1,res_ch2,res_amount;
    int main_menu = 1,cities_a,res_move;
    vector <string> city_names;
    bool play = true;

    printing.NewPage();
    printing.Title();
    timer.wait(1);
    cout << endl << endl;
    printing.MainMenu();
    cout << "Input: ";
    getline(cin, mm);

    while(main_menu != -1)
    {
        if(mm == "P")
        {
            string name_m = "Please input your city's name: ";
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
            cout << "Input: ";
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
            string ins3 = ins2;
            city_names.push_back(ins3);
        }
        for(int i = 0; i < city_names.size(); i++)
        {
            graph.addVertex(city_names[i]);
        }
        graph.addEdge();

        bool error = false;
        while (play = true)
        {
            printing.NewPage();
            if(error == true)
            {
                cout << "ERROR: Please enter a valid choice" << endl;
            }
            bool turn_completed = false;
            error = false;
            graph.print();
            printing.ActionMenu();
            cout << "Input: ";
            getline(cin, action_menu);
            if(action_menu == "A")
            {
                error = false;
                bool attack_menu_back = false;
                bool attack_menu_back_2 = false;
                while(attack_menu_back == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                    }
                    error = false;
                    printing.AttackMenu_1_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, att_ch1);
                    if(att_ch1 == "Back")
                    {
                        attack_menu_back = true;
                        break;
                    }
                    if(att_ch1 != "Back")
                    {
                        if(graph.findpcity(att_ch1) == true)
                        {
                            while(attack_menu_back_2 == false)
                            {
                                printing.NewPage();
                                if(error == true)
                                {
                                    cout << "ERROR: Please enter a valid city name." << endl;
                                    error = false;
                                }
                                printing.AttackMenu_2_B();
                                graph.print_p_adj(att_ch1);
                                printing.MenuEnd();
                                cout << "Input City Name: ";
                                getline(cin, att_ch2);
                                if(att_ch2 == "Back")
                                {
                                    attack_menu_back_2 == true;
                                    break;
                                }
                                if(att_ch2 != "Back")
                                {
                                    if(graph.findecity(att_ch2) == true)
                                    {
                                        graph.attack(att_ch1, att_ch2);
                                        turn_completed = true;
                                        break;
                                    }
                                    if(graph.findecity(att_ch2) == false)
                                    {
                                        error = true;
                                    }
                                }
                            }
                        }
                        if(graph.findpcity(att_ch1) == false)
                        {
                            error = true;
                        }
                    }
                }
                if(attack_menu_back == true)
                {
                    turn_completed == false;
                }
            }
            else if(action_menu == "F")
            {
                error = false;
                bool fortify_menu_back = false;
                while(fortify_menu_back == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        error = false;
                    }
                    printing.FortifyMenu_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, def_ch);
                    if(def_ch == "Back")
                    {
                        fortify_menu_back = true;
                        break;
                    }
                    if(def_ch != "Back")
                    {
                        if(graph.findpcity(def_ch) == true)
                        {
                            graph.fortify(def_ch);
                            turn_completed = true;
                            break;
                        }
                        if(graph.findpcity(def_ch) == false)
                        {
                            error = true;
                        }
                    }
                }
            }
            else if(action_menu == "W")
            {
                graph.wait();
                turn_completed = true;
            }
            else if(action_menu == "R")
            {
                error = false;
                bool resource_menu_back = false;
                bool resource_menu_back_2 = false;
                bool same_city = false;
                while(resource_menu_back == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                    }
                    error = false;
                    printing.ResourcesMenu_1_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, res_ch1);
                    cout << "Input Amount to move: ";
                    getline(cin, res_amount);
                    res_move = atoi(res_amount.c_str());
                    if(res_ch1 == "Back")
                    {
                        resource_menu_back = true;
                        break;
                    }
                    if(res_ch1 != "Back")
                    {
                        if(graph.findpcity(res_ch1) == true)
                        {
                            while(resource_menu_back_2 == false)
                            {
                                if(same_city != true)
                                {
                                    printing.NewPage();
                                }
                                same_city = false;
                                if(error == true)
                                {
                                    cout << "ERROR: Please enter a valid city name." << endl;
                                    error = false;
                                }
                                printing.ResourcesMenu_2_B();
                                graph.print_p();
                                printing.MenuEnd();
                                cout << "Input City Name: ";
                                getline(cin, res_ch2);
                                if(res_ch2 == res_ch1)
                                {
                                    printing.NewPage();
                                    cout << "ERROR: You cannot choose the same city." << endl;
                                    same_city = true;
                                }
                                else if(res_ch2 == "Back")
                                {
                                    resource_menu_back_2 == true;
                                    break;
                                }
                                else if((res_ch2 != "Back") && (res_ch2 != res_ch1))
                                {
                                    if(graph.findpcity(res_ch2) == true)
                                    {
                                        graph.resources(res_ch1,res_ch2, res_move);
                                        turn_completed = true;
                                        break;
                                    }
                                    if(graph.findpcity(res_ch2) == false)
                                    {
                                        error = true;
                                    }
                                }
                            }
                        }
                        if(graph.findpcity(res_ch1) == false)
                        {
                            error = true;
                        }
                    }
                }
                if(resource_menu_back == true)
                {
                    turn_completed == false;
                }
            }
            else if(action_menu == "Exit")
            {
                string exit_choice;
                cout << "Are you sure? (Y/N): ";
                getline(cin, exit_choice);
                if(exit_choice == "Y")
                {
                    break;
                }
                if(exit_choice == "N")
                {

                }
            }
            else
            {
                error = true;
            }
            if(turn_completed == true)
            {
                graph.turnresources();
            }
            //insert AI function
        }
    }
}

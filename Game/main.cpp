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

    string main_menu_choice,user_name,cities_amount_string;
    string action_menu;
    string att_ch1,att_ch2;
    string def_ch;
    string res_ch1,res_ch2,res_move_amount_string;
    int main_menu = 1,cities_amount,res_move;
    string ins2, ins3;
    char ins;
    vector <string> city_names;
    bool playing = true;
    bool name_error = false, resources_error = false, menu_error = false;
    bool menu_back_1 = false,menu_back_2 = false;
    bool turn_completed = false;
    bool same_city_check = false;

    printing.NewPage();
    printing.Title();
    cout << endl << endl << endl << endl << endl;
    printing.MainMenu();
    cout << "Input: ";
    getline(cin, main_menu_choice);

    while(main_menu != -1)
    {
        if(main_menu_choice == "P")
        {
            cout << "Please input your city's name: ";
            getline(cin, user_name);
            if(user_name == "Back")
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
        else if(main_menu_choice == "Q")
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
            getline(cin, main_menu_choice);
        }
    }

    if(main_menu != -1)
    {
        cout << "Please input the amount of cities you would play against (3-15): "; //cities amount message
        getline(cin, cities_amount_string);
        cities_amount = atoi(cities_amount_string.c_str());

        while((cities_amount < 3) || (cities_amount > 15))
        {
            cout << "Sorry out of bounds: "; //out of bounds message
            getline(cin, cities_amount_string);
            cities_amount = atoi(cities_amount_string.c_str());
        }
        cout << "Ready!" << endl;

        printing.NewPage();

        city_names.push_back(user_name);
        for(int i = 0; i < cities_amount; i++)
        {
            ins = 'A' + i;
            ins2 = string(1, ins);
            ins3 = ins2;
            city_names.push_back(ins3);
        }
        for(int i = 0; i < city_names.size(); i++)
        {
            graph.addVertex(city_names[i]);
        }
        graph.addEdge();

        while (playing == true)
        {
            turn_completed = false;
            menu_back_1 = false;
            menu_back_2 = false;

            printing.NewPage();
            if(menu_error == true)
            {
                cout << "ERROR: Please enter a valid choice" << endl;
                menu_error = false;
            }
            graph.print();
            printing.ActionMenu();
            cout << "Input: ";
            getline(cin, action_menu);

            if(action_menu == "A")
            {
                name_error = false;
                resources_error = false;
                menu_error = false;

                while(menu_back_1 == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(name_error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true)
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.AttackMenu_1_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, att_ch1);
                    if(att_ch1 == "Back")
                    {
                        menu_back_1 = true;
                        break;
                    }
                    if(att_ch1 != "Back")
                    {
                        if(graph.findpcity(att_ch1) == true)
                        {
                            if(graph.resourcecheck(att_ch1, 5) == true)
                            {
                                while(menu_back_2 == false)
                                {
                                    printing.NewPage();
                                    if(name_error == true)
                                    {
                                        cout << "ERROR: Please enter a valid city name." << endl;
                                        name_error = false;
                                    }
                                    printing.AttackMenu_2_B();
                                    graph.print_p_adj(att_ch1);
                                    printing.MenuEnd();
                                    cout << "Input City Name: ";
                                    getline(cin, att_ch2);
                                    if(att_ch2 == "Back")
                                    {
                                        menu_back_2 == true;
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
                                        else if(graph.findecity(att_ch2) == false)
                                        {
                                            name_error = true;
                                        }
                                    }
                                }
                            }
                            else if(graph.resourcecheck(att_ch1, 5) == false)
                            {
                                resources_error = true;
                            }
                        }
                        else if(graph.findpcity(att_ch1) == false)
                        {
                            name_error = true;
                        }
                    }
                }
                if(menu_back_1 == true)
                {
                    turn_completed == false;
                }
            }
            else if(action_menu == "F")
            {
                name_error = false;
                resources_error = false;
                menu_error = false;

                while(menu_back_1 == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(name_error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true)
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.FortifyMenu_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, def_ch);
                    if(def_ch == "Back")
                    {
                        menu_back_1 = true;
                        break;
                    }
                    if(def_ch != "Back")
                    {
                        if(graph.findpcity(def_ch) == true)
                        {
                            if(graph.resourcecheck(def_ch, 3) == true)
                            {
                                graph.fortify(def_ch);
                                turn_completed = true;
                                break;
                            }
                            else if(graph.resourcecheck(def_ch, 3) == false)
                            {
                                resources_error = true;
                            }
                        }
                        else if(graph.findpcity(def_ch) == false)
                        {
                            name_error = true;
                        }
                    }
                }
                if(menu_back_1 == true)
                {
                    turn_completed = false;
                }
            }
            else if(action_menu == "W")
            {
                graph.pwait();
                turn_completed = true;
            }
            else if(action_menu == "R")
            {
                name_error = false;
                resources_error = false;
                menu_error = false;

                while(menu_back_1 == false)
                {
                    if(turn_completed == true)
                    {
                        break;
                    }
                    printing.NewPage();
                    if(name_error == true)
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true)
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.ResourcesMenu_1_B();
                    graph.print_p();
                    printing.MenuEnd();
                    cout << "Input City Name: ";
                    getline(cin, res_ch1);
                    if(res_ch1 == "Back")
                    {
                        menu_back_1 = true;
                        break;
                    }
                    cout << "Input Amount to move: ";
                    getline(cin, res_move_amount_string);
                    res_move = atoi(res_move_amount_string.c_str());

                    if((res_ch1 != "Back") && (graph.resourcecheck(res_ch1, res_move) == true))
                    {
                        if(graph.findpcity(res_ch1) == true)
                        {
                            while(menu_back_2 == false)
                            {
                                if(same_city_check != true)
                                {
                                    printing.NewPage();
                                }
                                same_city_check = false;
                                if(name_error == true)
                                {
                                    cout << "ERROR: Please enter a valid city name." << endl;
                                    name_error = false;
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
                                    same_city_check = true;
                                }
                                else if(res_ch2 == "Back")
                                {
                                    menu_back_2 == true;
                                    break;
                                }
                                else if((res_ch2 != "Back") && (res_ch2 != res_ch1))
                                {
                                    if(graph.findpcity(res_ch2) == true)
                                    {
                                        graph.resources(res_ch1,res_ch2,res_move);
                                        turn_completed = true;
                                        break;
                                    }
                                    if(graph.findpcity(res_ch2) == false)
                                    {
                                        name_error = true;
                                    }
                                }
                            }
                        }
                        if(graph.findpcity(res_ch1) == false)
                        {
                            name_error = true;
                        }
                    }
                    else if(graph.resourcecheck(res_ch1, res_move) == false)
                    {
                        resources_error = true;
                    }
                    if(menu_back_1 == true)
                    {
                        turn_completed == false;
                    }
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
                menu_error = true;
            }
            if(turn_completed == true)
            {
                graph.turnresources();
            }
            //insert AI function
        }
    }
}

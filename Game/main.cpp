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
    string exit_choice;
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
            if(turn_completed != true)
            {
                printing.NewPage();
            }
            turn_completed = false; //these commands set all menu backs to false and starts a new turn
            menu_back_1 = false; //^
            menu_back_2 = false; //^

            //printing.NewPage(); //prints a new page
            if(menu_error == true) //if there is a menu error then print out the error and set the error bool to false
            {
                cout << "ERROR: Please enter a valid choice" << endl;
                menu_error = false;
            }
            graph.print(); //print the contents of the graph around each player city
            printing.ActionMenu(); //print the menu
            cout << "Input: "; //cout for an input
            getline(cin, action_menu); //getline for menu, using getline because we want to allow spaces

            if(action_menu == "A") //if action_menu == A go into attack menu, also using if statements because switch works better for ints
            {
                name_error = false; //set all possible errors to false
                resources_error = false; //^
                menu_error = false; //^

                while(menu_back_1 == false) //while menu level 1 is not wanting to go back
                {
                    if(turn_completed == true) //if the turn has been completed break
                    {
                        break;
                    }
                    printing.NewPage(); //print a new page
                    if(name_error == true) //print name error if there is one, then set the error to false
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true) //print resources error if there is one, then set the error to false
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.AttackMenu_1_B(); //print the beginning of the attack menu
                    graph.print_p(); //prints player cities (if p_controlled == true)
                    printing.MenuEnd(); //print the end of the menu
                    cout << "Input City Name: "; //input message
                    getline(cin, att_ch1); //getline, for spaces and simplicity
                    if(att_ch1 == "Back") //if player enters back set menu_back_1 bool to true, break from while loop
                    {
                        menu_back_1 = true;
                        break;
                    }
                    if(att_ch1 != "Back")//if player enters a name
                    {
                        if(graph.findpcity(att_ch1) == true) //and the name is found
                        {
                            if(graph.resourcecheck(att_ch1, 5) == true) //and the city has enough resources
                            {
                                while(menu_back_2 == false)
                                {
                                    printing.NewPage(); //print new page for next menu
                                    if(name_error == true) //display any errors, then set error to false
                                    {
                                        cout << "ERROR: Please enter a valid city name." << endl;
                                        name_error = false;
                                    }
                                    printing.AttackMenu_2_B(); //print the beginning of the menu
                                    graph.print_p_adj(att_ch1); //print any adj cities to player
                                    printing.MenuEnd(); //print the end of the menu
                                    cout << "Input City Name: "; //input message
                                    getline(cin, att_ch2); //getline, for spaces and simplicity
                                    if(att_ch2 == "Back") //if input is back, flip bool, break from current while loop
                                    {
                                        menu_back_2 == true;
                                        break;
                                    }
                                    if(att_ch2 != "Back") //if input isnt back
                                    {
                                        if(graph.findecity(att_ch1, att_ch2) == true)//and the city is found
                                        {

                                            graph.playerattack(att_ch1, att_ch2);     //run attack func on cities
                                            turn_completed = true; //complete the turn
                                            break; //break from current while
                                        }
                                        else if(graph.findecity(att_ch1, att_ch2) == false) //if the city isnt found, flip bool, restart while loop
                                        {
                                            name_error = true;
                                        }
                                    }
                                }
                            }
                            else if(graph.resourcecheck(att_ch1, 5) == false) //if there aren't enough resources to attack,
                            {
                                resources_error = true;
                            }
                        }
                        else if(graph.findpcity(att_ch1) == false) //if the city isn't found, flip bool, restart while loop
                        {
                            name_error = true;
                        }
                    }
                }
                if(menu_back_1 == true) //if we exit the attack menu, don't complete the turn
                {
                    turn_completed == false;
                }
            }
            else if(action_menu == "F") //if action_menu == F go into fortify menu, also using if statements because switch works better for ints
            {
                name_error = false; //set all errors to false
                resources_error = false; //^
                menu_error = false; //^

                while(menu_back_1 == false) //while the menu isnt trying to go back to the action menu
                {
                    if(turn_completed == true) //if the turn is completed break from this menu
                    {
                        break;
                    }
                    printing.NewPage(); //print a new page for the next menu
                    if(name_error == true) //if there is a name error print it and set bool to false
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true) //if there is a resource error print it and set bool to false
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.FortifyMenu_B(); //print beginning of fortify menu
                    graph.print_p(); //print player owned cities
                    printing.MenuEnd(); //print menu end
                    cout << "Input City Name: "; //input message
                    getline(cin, def_ch); //getline for menu, using getline because we want to allow spaces
                    if(def_ch == "Back") //if input is back set menu back 1 to true then break from this while loop
                    {
                        menu_back_1 = true;
                        break;
                    }
                    if(def_ch != "Back") //if input isnt back
                    {
                        if(graph.findpcity(def_ch) == true) //and the city is found
                        {
                            if(graph.resourcecheck(def_ch, 3) == true) //and the city has enough resources
                            {
                                graph.fortify(def_ch); //fortify func
                                turn_completed = true; //complete turn bool
                                break; //break from while loop
                            }
                            else if(graph.resourcecheck(def_ch, 3) == false) //if the city doesnt have enough resources set error to true let loop
                            {
                                resources_error = true;
                            }
                        }
                        else if(graph.findpcity(def_ch) == false) //if the city isnt found set error to true let loop
                        {
                            name_error = true;
                        }
                    }
                }
                if(menu_back_1 == true) //if the menu went from fortify to action menu dont complete the turn
                {
                    turn_completed = false;
                }
            }
            else if(action_menu == "W") //if action_menu == W go into wait
            {
                graph.pwait(); //run wait func
                turn_completed = true; //complete the turn
            }
            else if(action_menu == "R") //if action_menu == R go into Resources menu, also using if statements because switch works better for ints
            {
                name_error = false; //set all errors to false
                resources_error = false; //^
                menu_error = false; //^

                while(menu_back_1 == false) //while menus arent trying to travel from resource menu to action menu
                {
                    if(turn_completed == true) //iif the turn is completed break
                    {
                        break;
                    }
                    printing.NewPage(); //print a new page for the menu
                    if(name_error == true) //if error is true print error and set to false
                    {
                        cout << "ERROR: Please enter a valid city name." << endl;
                        name_error = false;
                    }
                    if(resources_error == true) //if resources_error is true print error and set to false
                    {
                        cout << "ERROR: You do not have enough resources." << endl;
                        resources_error = false;
                    }
                    printing.ResourcesMenu_1_B(); //print beginning of resources menu
                    graph.print_p(); //print player cities
                    printing.MenuEnd(); //print menu end
                    cout << "Input City Name: "; //input message
                    getline(cin, res_ch1); //getline
                    if(res_ch1 == "Back") //if the input is back, flip menu back 1 to true and break from this while loop
                    {
                        menu_back_1 = true;
                        break;
                    }
                    cout << "Input Amount to move: "; //ask how much should be moved
                    getline(cin, res_move_amount_string); //getline input
                    res_move = atoi(res_move_amount_string.c_str()); //convert input string to integer

                    if((res_ch1 != "Back") && (graph.resourcecheck(res_ch1, res_move) == true)) //if the input isnt back and the city has enough resources
                    {
                        if(graph.findpcity(res_ch1) == true) //and the city is found
                        {
                            while(menu_back_2 == false) //while we arent trying to move up a menu level
                            {
                                if(same_city_check != true) //if same city check is false print a new page
                                {
                                    printing.NewPage();
                                }
                                same_city_check = false; //set same city check to false
                                if(name_error == true) //if there is a name error print error and set to false
                                {
                                    cout << "ERROR: Please enter a valid city name." << endl;
                                    name_error = false;
                                }
                                printing.ResourcesMenu_2_B(); //print seconds menu for resources
                                graph.print_p(); //print player cities
                                printing.MenuEnd(); //print menu end
                                cout << "Input City Name: "; //input message
                                getline(cin, res_ch2); //getline
                                if(res_ch2 == res_ch1) //if the inputs match print a new page, print same city error, set same city check to true
                                {
                                    printing.NewPage();
                                    cout << "ERROR: You cannot choose the same city." << endl;
                                    same_city_check = true;
                                }
                                else if(res_ch2 == "Back") //if the input is back set menu back 2 to true break from this while loop
                                {
                                    menu_back_2 == true;
                                    break;
                                }
                                else if((res_ch2 != "Back") && (res_ch2 != res_ch1)) //if the input isnt back and the cities are not the same
                                {
                                    if(graph.findpcity(res_ch2) == true) //and the city is found
                                    {
                                        graph.resources(res_ch1,res_ch2,res_move); //move resources fun
                                        turn_completed = true; //complete the turn
                                        break; //break from this while loop
                                    }
                                    if(graph.findpcity(res_ch2) == false) //if the city isnt found flip error to true
                                    {
                                        name_error = true;
                                    }
                                }
                            }
                        }
                        if(graph.findpcity(res_ch1) == false) //if the city isnt found flip error to true
                        {
                            name_error = true;
                        }
                    }
                    else if(graph.resourcecheck(res_ch1, res_move) == false) //if the initial city doesnt have enough resources flip error to true
                    {
                        resources_error = true;
                    }
                    if(menu_back_1 == true) //if the menu si trying to move from resources menu to action menu dont complete the turn
                    {
                        turn_completed == false;
                    }
                }
            }
            else if(action_menu == "Exit") //if the input is exit
            {
                cout << "Are you sure? (Y/N): "; //ask them if they are sure
                getline(cin, exit_choice); //getline
                if(exit_choice == "Y") //if the input is Y (yes) break the play while loop
                {
                    break;
                }
                if(exit_choice == "N") //if the input is N (no) dont do anything
                {

                }
            }
            else
            {
                menu_error = true; //if they input anything other than A, F, W, R, Exit then flip error
            }

            if(turn_completed == true) //if the turn was completed under any action give turn resources to all players and give AI turns
            {
                printing.NewPage();
                graph.AIturns();
                graph.turnresources();
            }
            if(graph.win_check() == true)
            {
                printing.NewPage();
                printing.win();
                break;
            }
            else if(graph.lose_check() == true)
            {
                printing.NewPage();
                printing.lose();
                break;
            }
        }
    }
}

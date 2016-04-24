#include "Printing.h"
#include "Graph.h"
#include <iostream>
#include <stdio.h>

Printing::Printing()
{

}

void Printing::NewPage()
{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

void Printing::MainMenu()
{
    cout << "╔════════════════════Main Menu════════════════════╗" << endl;
    cout << "║      - Pick and option to start, or quit! -     ║" << endl;
    cout << "║  -Play Game (P)                                  " << endl;
    cout << "║  -Quit Game (Q)                                 ║" << endl;
    cout << "╚═════════════════════════════════════════════════╝" << endl;
}

void Printing::ActionMenu()
{
    cout << "╔═══════════════════Action Menu═══════════════════╗" << endl;
    cout << "║         - Pick an action for your turn -        ║" << endl;
    cout << "║  -Attack (A) -- -5 Resources" << endl;
    cout << "║  -Fortify (F) -- -3 Resources" << endl;
    cout << "║  -Wait (W) -- +5 Resources" << endl;
    cout << "║  -Manage Resources (R)" << endl;
    cout << "║  -Exit (Exit)                                   ║" << endl;
    cout << "╚═════════════════════════════════════════════════╝" << endl;
}

void Printing::FortifyMenu_B()
{
    cout << "╔═══════════════════Fortify Menu══════════════════╗" << endl;
    cout << "║             -Pick a city to fortify-            ║" << endl;
}

void Printing::AttackMenu_1_B()
{
    cout << "╔═══════════════════Attack Menu═══════════════════╗" << endl;
    cout << "║           -Pick a city to attack from-          ║" << endl;
}

void Printing::AttackMenu_2_B()
{
    cout << "╔═══════════════════Attack Menu═══════════════════╗" << endl;
    cout << "║             -Pick a city to attack-             ║" << endl;
    cout << "║               -(Just the letter)-               ║" << endl;
}

void Printing::ResourcesMenu_1_B()
{
    cout << "╔══════════════════Resources Menu═════════════════╗" << endl;
    cout << "║       -Pick a city to move resources from-      ║" << endl;
}

void Printing::ResourcesMenu_2_B()
{
    cout << "╔══════════════════Resources Menu═════════════════╗" << endl;
    cout << "║        -Pick a city to move resources to-       ║" << endl;
}

void Printing::MenuEnd()
{
    cout << "║  -Back (Back)                                   ║" << endl;
    cout << "╚═════════════════════════════════════════════════╝" << endl;
}

void Printing::Title()
{
    cout << "██████╗ ██╗███████╗ ██████╗" << endl;
    cout << "██╔══██╗██║██╔════╝██╔════╝" << endl;
    cout << "██████╔╝██║███████╗██║     " << endl;
    cout << "██╔══██╗██║╚════██║██║     " << endl;
    cout << "██║  ██║██║███████║╚██████╗" << endl;
    cout << "╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝" << endl;
}

Printing::~Printing()
{
    //dtor
}

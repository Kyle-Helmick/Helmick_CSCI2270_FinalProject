#include "Printing.h"
#include "Timer.h"
#include "Graph.h"
#include <iostream>
#include <stdio.h>

Printing::Printing()
{

}

void Printing::TextPrint(string message)
{
    Timer timer;
    for(int i = 0; i < message.size(); i++)
    {
        cout << message[i];
        timer.wait(.01);
        fflush(stdout);
    }
}

void Printing::NewPage()
{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

void Printing::MainMenu()
{
    cout << "#####################Main Menu#####################" << endl;
    cout << "#      - Pick and option to start, or quit! -     #" << endl;
    cout << "#  -Play Game (P)                                  " << endl;
    cout << "#  -Quit Game (Q)                                 #" << endl;
    cout << "###################################################" << endl;
    cout << "Input: ";
}

void Printing::ActionMenu()
{
    cout << "####################Action Menu####################" << endl;
    cout << "#         - Pick an action for your turn -        #" << endl;
    cout << "#  -Attack (A)" << endl;
    cout << "#  -Fortify (F)" << endl;
    cout << "#  -Wait (W)" << endl;
    cout << "#  -Back (Back)                                   #" << endl;
    cout << "###################################################" << endl;
    cout << "Input: ";
}

void Printing::FortifyMenu_B()
{
    cout << "####################Fortify Menu###################" << endl;
    cout << "#             -Pick a city to fortify-            #" << endl;
}

void Printing::AttackMenu_1_B()
{
    cout << "####################Attack Menu####################" << endl;
    cout << "#           -Pick a city to attack from-          #" << endl;
}

void Printing::AttackMenu_2_B()
{
    cout << "####################Attack Menu####################" << endl;
    cout << "#             -Pick a city to attack-             #" << endl;
}

void Printing::MenuEnd()
{
    cout << "#  -Back (Back)                                   #" << endl;
    cout << "###################################################" << endl;
    cout << "Input City Name: ";
}

Printing::~Printing()
{
    //dtor
}

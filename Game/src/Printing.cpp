#include "Printing.h"
#include "Timer.h"
#include <iostream>
#include <stdio.h>

Printing::Printing()
{
    //ctor
}

void Printing::TextPrint(string message)
{
    Timer timer;
    for(int i = 0; i < message.size(); i++)
    {
        cout << message[i];
        timer.wait(0);
        fflush(stdout);
    }
}

Printing::~Printing()
{
    //dtor
}

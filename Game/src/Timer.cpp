#include "Timer.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

Timer::Timer()
{
    //ctor
}

void Timer::wait(float seconds)
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait);
}

Timer::~Timer()
{
    //dtor
}

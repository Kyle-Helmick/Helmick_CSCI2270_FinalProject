#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int main ()
{
    for (int i=0; i<[insert variable here]; i++)
    {
        //this is where you would put a function to be called
        wait(1); //time increments of one
        //fflush(stdout) //this is used for printing
    }
  return 0;
}

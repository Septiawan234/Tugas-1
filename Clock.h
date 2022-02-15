#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <stdlib.h>

//#include <clock.h>

struct hour
{
    int h;
};
struct minute{
int m;
};
struct second{
int s;
};

struct clock
{
    hour hh;
    minute mm;
    second ss;
};

bool IsValid (int hh, int mm, int ss);

clock MakeClock (int hh, int mm, int ss);

hour GetHour(clock c);
minute GetMinute (clock c);
second GetSecond (clock c);

void SetHour (clock c, int newHH);
void SetMinute(clock c, int newMM);
void SetSecond(clock c, int newSS);


clock AddClock (clock c1, clock c2);

void PrintClock (clock c);


#endif

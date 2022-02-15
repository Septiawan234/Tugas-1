#include <iostream>
#include "clock.h"

using namespace std;

bool IsValid (int hh, int mm, int ss)
{
    if(((hh>=0 && hh<=23) && (mm>=0 && mm<=59)) && ((ss>=0)&&(ss<=59)))
        return true;
    else
        return false;
}

clock MakeClock( int hh, int mm, int ss)
{
    clock c;
    c.hh.h = hh; 
	c.mm.m = mm; 
	c.ss.s = ss;
    return c;
}

hour GetHour(clock c)
{
    return c.hh;
}

minute GetMinute (clock c)
{
    return c.mm;
}

second GetSecond (clock c)
{
    return c.ss;
}

void SetHour (clock c, hour newHH)
{
    c.hh= newHH;
}

void SetMinute(clock c, minute newMM)
{
    c.mm = newMM;
}

void SetSecond(clock c, second newSS)
{
    c.ss = newSS;
}

clock AddClock (clock c1, clock c2)
{
    clock sisa;
    if ((c1.ss.s+c2.ss.s) >=60)
    {
        sisa.ss.s = (c1.ss.s+c2.ss.s) - 60;
        sisa.mm.m = 1;
    }
    else
    {
        sisa.ss.s = c1.ss.s+c2.ss.s;
    }

    if ((c1.mm.m+c2.mm.m) >=60)
    {
        sisa.mm.m = (sisa.mm.m+c1.mm.m+c2.mm.m) - 60;
        sisa.hh.h = 1;
    }
    else
    {
        sisa.mm.m = c1.mm.m+c2.mm.m;
    }

    if (c1.hh.h+c2.hh.h >=24)
    {
        sisa.hh.h = (sisa.hh.h+c1.hh.h+c2.hh.h) - 60;
    }
    else
    {
        sisa.hh.h = c1.hh.h+c2.hh.h;
    }
    return sisa;
}

void PrintClock (clock c)
{
    cout<<c.hh.h<<" : "<<c.mm.m<<" : "<<c.ss.s<<endl;
}

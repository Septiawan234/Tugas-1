#include "clock.h"
using namespace std;

 int main()
 {
    clock c1 = MakeClock(2,30,4);
    clock c2 = MakeClock(6,0,0);
    clock sisa = MakeClock(1,62,30);

    PrintClock(c1);
    PrintClock(c2);

    sisa = AddClock(c1, c2);
    PrintClock(sisa);

    return 0;
 }

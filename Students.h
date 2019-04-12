#ifndef Students_H
#define Students_H
#include <iostream>

using namespace std;

class Students 
{
    public:
        Students();
        Students(int w, int e); // takes in window time and entry time 
        ~Students();

        int windowTime;
        int entryTime;
        int queueTime;
        int idleTime;
};

#endif
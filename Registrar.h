#ifndef Registrar_H
#define Registrar_H
#include <iostream>
#include <string>
#include "Students.h"
#include "GenQueue.h"

using namespace std;

class Registrar 
{
    private:
        int inputInt; 
        int entryTime;
        int windowTime;
        int studentNum; // number of students
        int medianArrCount; // count of median array 
        int idleArrCount; // count of idle array 

    public:
        Registrar(); // default constructor
        ~Registrar(); // destructor

        bool getFile(string file); // read in file 
        bool timer(int t); // timer

        // students
        double meanStud();
        double medianStud();
        int longestStud();
        int overTenStud();

        // window 
        double meanIdle();
        int longestIdle();
        int idleOverFive();

        GenQueue<int> waitStats;
        GenQueue<int> idleStats;

        Students* *windowArr;
        GenQueue<Students> studentQ;

        int *medianArray;
        int *idleArray;

        int totalWindows;
        int totalStudents;
};

#endif
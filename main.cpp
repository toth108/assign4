#include <iostream>
#include <string>
#include "Registrar.h"

using namespace std;

int main(int argc, char** argv) 
{
    Registrar r;

    string file = argv[1];
    
    int currTime = 0;
    int openWindows = 0;

    bool running = true;

    if(r.getFile(file)) 
    {
        while(running) 
        {
            if(r.studentQ.isEmpty()) // if queue is empty 
            {
                int temp = 0;
    
                for(int i = 0; i < r.totalWindows; ++i) 
                {
                    if((r.windowArr[i]->windowTime) < 1) 
                    {
                        temp++;
                    }
                }
                if(temp == r.totalWindows) 
                {
                    running = false;
                }
            }
            for(int i = 0; i < r.totalWindows; ++i) // check for avilable window 
            {
                Students* student; 

                if(r.windowArr[i]->windowTime < 1) 
                {
                    if(!r.studentQ.isEmpty()) 
                    {
                        // this error has stumped Mark, Aimee, and I. 
                        // I admit defeat. 
                        // it has beaten me. 
                        // all the errors revolve around the Students / student pointer 
                        student = r.studentQ.qFront(); 
        
                        if(student->entryTime <= currTime) 
                        {
                            if(r.windowArr[i]->idleTime > 0) 
                            {
                                r.idleStats.enqueue(r.windowArr[i]->idleTime);
                            }
                            r.windowArr[i] = r.studentQ.dequeue();
                            r.waitStats.enqueue(r.windowArr[i]->queueTime);
                        }
                    }
                }
            }
            currTime++;
            r.timer(currTime);
        }
        for(int i = 0; i < r.totalWindows; ++i) // idle windows 
        {
            if(r.windowArr[i]->idleTime > 0) 
            {
                r.idleStats.enqueue(r.windowArr[i]->idleTime);
            }
        }

        // print out collected student stats 
        cout << "Student Stats" << endl;
        cout << "Mean student wait wime: " << r.meanStud() << endl;
        cout << "Median student wait time: " << r.medianStud() << endl;
        cout << "Longest student wait time: " << r.longestStud() << endl;
        cout << "Students waiting over ten minutes: " << r.overTenStud() << endl;
        cout << "\n" << endl;

        // print out collected window stats 
        cout << "Window Stats" << endl;
        cout << "Mean Window Idle Time: " << r.meanIdle() << endl;
        cout << "Longest Window Idle Time: " << r.longestIdle() << endl;
        cout << "Idle Time Over Five Minutes: " << r.idleOverFive() << endl;
        }
    return 0;
}
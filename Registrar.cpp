#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
#include "Registrar.h"
#include "Students.h"

using namespace std;

Registrar::Registrar() 
{
    inputInt = 1;
    entryTime = 0;
    windowTime = 0;

    studentNum = 0;
    medianArrCount = 0;
    idleArrCount = 0;

    totalWindows = 0;
    totalStudents = 0;
}

Registrar::~Registrar() 
{
    delete [] windowArr;
    delete [] idleArray;
    delete [] medianArray;
}

bool Registrar::getFile(string file) 
{
    string line;
    int lineNum = 1;

    ifstream inputFile;
    inputFile.open(file.c_str());
    
    getline(inputFile, line);
    totalWindows = atoi(line.c_str());

    windowArr = new Students*[totalWindows];

    for(int i = 0; i < totalWindows; ++i) 
    {
        Students* student = new Students();
        windowArr[i] = student;
    }

    lineNum++;

    while(getline(inputFile, line)) 
    {
        switch(inputInt) 
        {
            case(1): // timer 
            {
                entryTime = atoi(line.c_str());
                inputInt++;
                lineNum++;

                break;
            }

            case(2): // student num 
            {
                if(line != "") 
                {
                    studentNum = atoi(line.c_str());
                        
                    for(int i = 0; i < studentNum; ++i) 
                    {
                        getline(inputFile, line);
                        lineNum++;

                        windowTime = atoi(line.c_str());

                        totalStudents++;

                        Students student = Students(windowTime, entryTime);

                        studentQ.enqueue(student);
                    }
                    
                    inputInt--; 
                }

                break;
            }
        }
    }
    return true;
}

bool Registrar::timer(int t) 
{
    for(int i = 0; i < totalWindows; ++i) 
    {
        if(windowArr[i]->windowTime > 0) 
        {
            //Decreases when Student at Window
            windowArr[i]->windowTime--;
        }
        else 
        {
            //Increases when Student NOT at Window
            windowArr[i]->idleTime++;
        }
    }

    if(!studentQ.isEmpty()) 
    {
        ListNode<Students> *curr = studentQ.front;

        while(curr != NULL) 
        {
            if(curr->data->entryTime < t) 
            {
                curr->data->queueTime += 1;
            }
            curr = curr->next;
        }
    }
    return true;
}

double Registrar::meanStud() 
{
    ListNode<int> *curr = waitStats.front;

    double minWait = 0;
    double sum = 0;
    double counter = 0;

    while(curr != NULL) 
    {
        sum += curr->data;
        curr = curr->next;
        counter++;
    }
    if(counter == 0) 
    {
        return 0;
    }
    minWait = sum / counter;
    return minWait;
}

double Registrar::medianStud() 
{
    ListNode<int> *curr = waitStats.front;

    double medWait = 0;
    medianArrCount = 0;

    while(curr != NULL) 
    {
        curr = curr->next;
        medianArrCount++;
    }

    if(medianArrCount == 0) 
    {
        return 0;
    }
    else 
    {
        medianArray = new int[medianArrCount];
        curr = waitStats.front;

        for(int i = 0; i < medianArrCount; ++i) 
        {
            medianArray[i] = curr->data;
            curr = curr->next;
        }

        sort(medianArray, medianArray + medianArrCount);

        if(medianArrCount % 2 == 1) 
        {
            double d = 0;
            int r = 0;

            r = (medianArrCount/2) + 1;
            d = medianArray[r];

            return d;
        }
        else 
        {
            double d = 0;
            int a = 0;
            int z = 0;

            a = medianArrCount/2;
            z = (medianArrCount/2) + 1;

            if(medianArray[z] == 0) 
            {
                return 0;
            }

            d = double(medianArray[a])/double(medianArray[z]);

            return d;
        }
    }
}

int Registrar::longestStud() 
{
    if(medianArrCount == 0) 
    {
        return 0;
    }
    else 
    {
        return medianArray[medianArrCount - 1];
    }
}

int Registrar::overTenStud() 
{
    if(medianArrCount == 0) 
    {
        return 0;
    }
    else 
    {
        int temp = 0;

        for(int i = 0; i < medianArrCount; ++i) 
        {
            if(medianArray[i] > 10) 
            {
                ++temp;
            }
        }
        return temp;
    }
}

double Registrar::meanIdle() 
{
    ListNode<int> *curr = idleStats.front;

    double minIdle = 0;
    double sum = 0;
    double counter = 0;

    while(curr != NULL) 
    {
        sum += curr->data;
        curr = curr->next;

        counter++;
    }

    if(counter == 0) 
    {
        return 0;
    }

    minIdle = sum / counter;
    return minIdle;
}

int Registrar::longestIdle() 
{
    ListNode<int> *curr = idleStats.front;

    idleArrCount = 0;

    while(curr != NULL) 
    {
        curr = curr->next;
        idleArrCount++;
    }

    idleArray = new int[idleArrCount];

    curr = idleStats.front;

    for(int i = 0; i < idleArrCount; ++i) 
    {
        idleArray[i] = curr->data;
        curr = curr->next;
    }

    sort(idleArray, idleArray + idleArrCount);

    return(idleArray[idleArrCount - 1]);
}

int Registrar::idleOverFive() 
{
    int temp = 0;

    for(int i = 0; i < idleArrCount; ++i) 
    {
        if(idleArray[i] > 5) 
        {
            ++temp;
        }
    }

    return temp;
}
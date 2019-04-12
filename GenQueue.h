#ifndef GenQueue_H
#define GenQueue_H
#include <iostream>
#include "ListNode.h"

using namespace std;

template <class TempQ>
class GenQueue 
{
    public: 
        int numElem;
        ListNode<TempQ> *front;
        ListNode<TempQ> *back;

        GenQueue();
        ~GenQueue();

        void enqueue(TempQ d);
        TempQ dequeue();

        TempQ qFront(); 
        TempQ qBack();

        void printQ();
        bool isEmpty();
        int getSize();
};

#endif
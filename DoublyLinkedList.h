#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include <iostream>
#include "ListNode.h"

using namespace std;

template <class DLLtemp>
class DoublyLinkedList {
    private:

    public:
        unsigned int size;
        ListNode<DLLtemp> *front;
        ListNode<DLLtemp> *back;

        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertBack(DLLtemp data);
        DLLtemp removeFront();
        DLLtemp getFront();

        void printList();
        void deletePos(int pos);
        
        bool isEmpty();
        unsigned int getSize();
};

#endif
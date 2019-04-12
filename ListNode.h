#ifndef ListNode_H
#define ListNode_H
#include <iostream>

using namespace std;

template <class nodeTemp>
class ListNode 
{
    public:
        nodeTemp data;
        ListNode<nodeTemp> *next;
        ListNode<nodeTemp> *prev;

        ListNode(); // default constructor
        ListNode(nodeTemp data); // overloaded constructor 
        ~ListNode(); // destructor
};

#endif
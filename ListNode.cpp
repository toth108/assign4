#include <iostream>
#include "ListNode.h"

template <class nodeTemp>
ListNode<nodeTemp>::ListNode() 
{

}

// takes in data 
template <class nodeTemp>
ListNode<nodeTemp>::ListNode(nodeTemp d) 
{
    data = d;
    next = NULL;
    prev = NULL;
}

template <class nodeTemp>
ListNode<nodeTemp>::~ListNode() 
{
    if(next != NULL) 
    {
        next = NULL;
        prev = NULL;

        delete next;
        delete prev;
    }
}
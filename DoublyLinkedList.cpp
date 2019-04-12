#include <iostream>
#include "DoublyLinkedList.h"

template <class DLLtemp>
DoublyLinkedList<DLLtemp>::DoublyLinkedList() 
{
    size = 0;
    front = NULL;
    back = NULL;
}

template <class DLLtemp>
DoublyLinkedList<DLLtemp>::~DoublyLinkedList() 
{

}

// insert node at back 
template <class DLLtemp>
void DoublyLinkedList<DLLtemp>::insertBack(DLLtemp d) 
{
    ListNode<DLLtemp> *node = new ListNode<DLLtemp>(d);
    
    if(size == 0) 
    {
        front = node;
    }
    else 
    {
        back->next = node;
        node->prev = back;
    }

    back = node;
    size++;
}

// removes front node 
template <class DLLtemp>
DLLtemp DoublyLinkedList<DLLtemp>::removeFront() 
{
    if(!isEmpty()) 
    {
        ListNode<DLLtemp> *node = front;

        if(front->next == NULL) // list = 1
        {
            front = NULL;
            back = NULL;
        }
        else // > 1
        {
            front->next->prev = NULL;
            front = front->next;
        }

        DLLtemp temp = node->data;

        delete node;
        size--;
        return temp;
    }
    else 
    {
        return DLLtemp();
    }
}

// returns front node 
template <class DLLtemp>
DLLtemp DoublyLinkedList<DLLtemp>::getFront() 
{
    return front->data;
}

// prints out list 
template <class DLLtemp>
void DoublyLinkedList<DLLtemp>::printList() 
{
    ListNode<DLLtemp> *curr = front;

    while(true) 
    {
        if(curr->next == NULL) 
        {
            break;
        }

        cout << curr->data << endl;
        curr = curr->next;
    }
}

// deletes node and adjusts curr 
template <class DLLtemp>
void DoublyLinkedList<DLLtemp>::deletePos(int pos) 
{
    int idx = 0;
    ListNode<DLLtemp> *curr = front;
    ListNode<DLLtemp> *prev = front;

    while(idx != pos) 
    {
        prev = curr;
        curr = curr->next;
        idx++;
    }

    prev->next = curr->next;
    curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    curr->data = NULL;

    size--;
    delete curr;
}

// checks if list is empty 
template <class DLLtemp>
bool DoublyLinkedList<DLLtemp>::isEmpty() 
{
    return(size == 0);
}

// returns size of list 
template <class DLLtemp>
unsigned int DoublyLinkedList<DLLtemp>::getSize() 
{
    return size;
}
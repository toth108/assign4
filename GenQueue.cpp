#include <iostream>
#include "ListNode.h"
#include "GenQueue.h"

template <class TempQ>
GenQueue<TempQ>::GenQueue() 
{
    numElem = 0;
    front = NULL;
    back = NULL;
}

template <class TempQ>
GenQueue<TempQ>::~GenQueue() 
{

}

// returns front element 
template <class TempQ>
TempQ GenQueue<TempQ>::qFront() 
{
    return front->data;
}

// returns back element 
template <class TempQ>
TempQ GenQueue<TempQ>::qBack() 
{
    return back->data;
}

// prints queue 
template <class TempQ>
void GenQueue<TempQ>::printQ() 
{
    ListNode<TempQ> *curr = front;

    while(true) 
    {
        if(curr != NULL) 
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
        else 
        {
            break;
        }
    }
}

// checks if queue is empty 
template <class TempQ>
bool GenQueue<TempQ>::isEmpty() 
{
    return (numElem == 0);
}

// returns size of queue 
template <class TempQ>
int GenQueue<TempQ>::getSize() 
{
    return numElem;
}

// adds element to queue 
template <class TempQ>
void GenQueue<TempQ>::enqueue(TempQ d) 
{
    ListNode<TempQ> *node = new ListNode<TempQ>(d);

    if(numElem == 0) 
    {
        front = node;
    }
    else 
    {
        back->next = node;
        node->prev = back;
    }

    back = node;
    numElem++;
}

// returns and nulls queue element 
template <class TempQ>
TempQ GenQueue<TempQ>::dequeue() 
{
    if(!isEmpty()) 
    {
        ListNode<TempQ> *node = front;

        TempQ temp = node->data;

        if(front->next == NULL) 
        {
            front = NULL;
            back = NULL;
        }
        else 
        {
            front->next->prev = NULL;
            front = front->next;
        }
        
        delete node;
        numElem++;

        return temp;
    }
    else 
    {
        return TempQ();
    }
}
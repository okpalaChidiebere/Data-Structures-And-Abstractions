//--------------------------------------------------------------------
//
//  Laboratory 11                                        queuelnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------
#pragma warning( disable : 4290 ) //get rid of exception warnings

#include <stdexcept>
#include <new>
#include "queuelnk.h"

using namespace std;

//--------------------------------------------------------------------

template < class DT >
QueueNode<DT>:: QueueNode( const DT &nodeDataItem,
                           QueueNode<DT> *nextPtr )

// Creates a queue node containing data item nodeDataItem and next
// pointer nextPtr.

  : dataItem(nodeDataItem),
    next(nextPtr)
{}

//--------------------------------------------------------------------

template < class DT >
Queue<DT>:: Queue ( int ignored )

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

  : front(0),
    rear(0)
{}

//--------------------------------------------------------------------

template < class DT >
Queue<DT>:: ~Queue ()

// Frees the memory used by a queue.

{
    clear();
}

//--------------------------------------------------------------------

template < class DT >
void Queue<DT>:: enqueue ( const DT &newDataItem )
    throw ( logic_error )

// Inserts newElement at the rear of a queue.

{
    QueueNode<DT> *p;   // Pointer to enqueued data item
	
    p=new QueueNode<DT>(newDataItem,NULL);//make p a new QueueNode that has newDataItem and link of zero

    if(front==NULL)//If there are no nodes, set the front to be this new node
		front=p;
	else
    //Otherwise, add the new node to the end
	{
    rear->next=p;
	}
	p=rear;//Reassign the rear to p
	
}

//--------------------------------------------------------------------

template < class DT >
DT Queue<DT>:: dequeue () throw ( logic_error )

// Removes the least recently (front) element from a queue and
// returns it.

{
    QueueNode<DT> *p;   // Pointer to dequeued node
    DT temp;            // Temporarily stores dequeued element

    // Requires that the queue is not empty
    if ( front == 0 )
        throw logic_error("list is empty");

    temp = front->dataItem;
    p = front;
    front = front->next;
    if ( front == 0 )
       rear = 0;
    delete p;

    return temp;
}

//--------------------------------------------------------------------

template < class DT >
void Queue<DT>:: clear ()

// Removes all the elements from a queue.

{
    QueueNode<DT> *p,       // Points to successive nodes
                  *nextP;   // Stores pointer to next node
    p = front;
    while ( p != 0 )
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    front = 0;
    rear  = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Queue<DT>:: isEmpty () const

// Returns true if a queue is empty. Otherwise, returns false.

{
    return ( front == 0 );
}

//--------------------------------------------------------------------

template < class DT >
bool Queue<DT>:: isFull () const

// Returns true if a queue is full. Otherwise, returns false.

{
    // This is a somewhat hacked way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
    QueueNode<DT> *p;
    DT junk;

    try
    {
        p = new QueueNode<DT>(junk, 0);
    }
    catch ( bad_alloc &e )
    {
        return true;
    }

    delete p;
    return false;
}


//--------------------------------------------------------------------

template < class DT >
void Queue<DT>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
    QueueNode<DT> *p;   // Iterates through the queue

    if ( front == 0 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "front ";
       for ( p = front ; p != 0 ; p = p->next )
           cout << p->dataItem << " ";
       cout << "rear" << endl;
    }
}

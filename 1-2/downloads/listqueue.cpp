#include "queue.h"
#include <iostream>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    // TODO: Initialize front_node and rear_node
    front_node=nullptr;
    rear_node=nullptr;
    // TODO: Initialize current_size to 0
    current_size=0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    Node* newNode=new Node(item);
    // TODO: Link the new node to the rear
    if(rear_node!=nullptr) rear_node->next=newNode;
    else front_node=newNode;
    // TODO: Update the rear_node
    rear_node=newNode;
    // TODO: Increment the current size
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    // TODO: Store the data from the front node
    int val=front_node->data;
    // TODO: Update the front pointer to the next node
    Node* temp=front_node;
    front_node=front_node->next;
    // TODO: Update the rear pointer if the queue becomes empty
    if(front_node==nullptr) rear_node=nullptr;
    // TODO: Delete the old front node
    delete temp;
    // TODO: Decrement current_size
    current_size--;
    // TODO: Return the stored data
    return val;
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    while(front_node!=nullptr){
        Node* temp=front_node;
        front_node=front_node->next;
        delete temp;
    }
    // TODO: Reset front and rear pointer
    rear_node=nullptr;
    // TODO: Reset current_size to 0
    current_size=0;
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    // TODO: Return the data from the front node without removing it
    return front_node->data;
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    // TODO: Return the data from the back node without removing it
    return rear_node->data;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    return front_node==nullptr;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    // TODO: Traverse the linked list from front
    string result="<";
    Node* current=front_node;
    while(current!=nullptr){
        result+=to_string(current->data);
        if(current->next!=nullptr) result+=", ";
        current=current->next;
    }
    result+="|";
    return result;
}

#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    data=nullptr;
    capacity=initial_capacity;
    front_idx=0;
    rear_idx=-1;
    // TODO: Allocate memory for the array with the specified initial capacity
    data=new int[capacity];
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    if(size()>=capacity){
        resize(capacity*2);
    }
    // TODO: Add the new element to the rear of the queue
    if(rear_idx==-1){
        front_idx=0;
        rear_idx=0;
    }
    else rear_idx=(rear_idx+1)%capacity;
    data[rear_idx]=item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    int val=data[front_idx];
    if(front_idx==rear_idx){
        front_idx=0;
        rear_idx=-1;
    }
    else front_idx=(front_idx+1)%capacity;
    if(size()<=capacity/4 and capacity>2) resize(capacity/2);
    return val;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    front_idx=0;
    rear_idx=-1;
    if(capacity>2) resize(2);
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    if(rear_idx==-1) return 0;
    else if(rear_idx>=front_idx) return rear_idx-front_idx+1;
    else return capacity-(front_idx-rear_idx-1);
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    // TODO: Return the element at the front of the queue without removing it
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()) return -1;
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return size()==0;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string result="<";
    for(int i=0;i<size();i++){
        result+=to_string(data[(front_idx+i)%capacity]);
        if(i!=size()-1) result+=", ";
    }
    result+="|";
    return result;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    int old_size=size();
    // TODO: Create a new array with the new capacity
    int* new_data=new int[new_capacity];
    // TODO: Copy elements from the old array to the new array
    for(int i=0;i<old_size;i++) new_data[i]=data[(front_idx+i)%capacity];
    // TODO: Delete the old array
    delete[] data;
    // TODO: Update the data pointer and capacity
    data=new_data;
    capacity=new_capacity;
    // TODO: Update front and rear indices
    front_idx=0;
    if(old_size==0) rear_idx=-1;
    else rear_idx=old_size-1;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}
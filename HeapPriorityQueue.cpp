#include "HeapPriorityQueue.h"
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue() {
    // Initialize size to 0
    if (MAX_SIZE > 0) 
    {
        size = 0;
    }
    else
    {
        size = -1; // invalid size (check for safety)
    }
}

// TODO: Implement the destructor
HeapPriorityQueue::~HeapPriorityQueue() {
    // Cleanup if necessary
    // nothing needing becasue is onyl using an array with a fixed size
}

// TODO: Implement the copy constructor
HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue& other) {
    // Copy heap elements and size
    size = other.size;

    for (int i = 0; i < size; ++i) // copy each element
    {
        heap[i] = other.heap[i]; // use PrinterJob's assignment operator
    }
}

// TODO: Implement the copy assignment operator
HeapPriorityQueue& HeapPriorityQueue::operator=(const HeapPriorityQueue& other) {
    // Assign heap elements and size properly
    if (this != &other) // self assignment check
    {
        size = other.size;

        // same for loop as the copyig constructor
        for (int i = 0; i < size; ++i) // copy each element
        {
            heap[i] = other.heap[i]; // use PrinterJob's assignment operator
        }
    }

    return *this; // returns the current object
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp
    // check if the heap is full
    if (size >= MAX_SIZE)
    {
        cout << "!!! the heap is full !!!";
        return;
    }

    // load the queue from the butt
    heap[size].printString = str; // create a new PrinterJob at the end of the heap
    heap[size].priority = priority; // assign the values

    // move it up based on priority to where it should go in the queue
    percolateUp(size);

    // increase the size of the heap
    size = size + 1;
}

// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    // base case check if the heap is empty
    if (size <= 0)
    {
        cout << "!!! the heap is empty !!!";
        return;
    }

    cout << "Printing jobs in priority order:\n";

    // continue until the heap is empty
    while (size > 0)
    {
        // print the root of the heap which is the job with the most priority
        cout << heap[0].printString << " (Priority: " << heap[0].priority << ")\n";

        // move the last element to the root
        heap[0] = heap[size - 1];

        // make the heap smaller
        size = size - 1;

        // move the root down the heap
        percolateDown(0);
    }
}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
    // continue until we reach the root or the parent has higher priority
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2; // calculate the parent index usnng the tech we learned in class

        // check if the current node has higher priority than the parent
        if (heap[index] < heap[parentIndex]) // if current node has lower priority number
        {
            // switch around the current node with the parent
            PrinterJob temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp; 

            // move up to the parents index
            index = parentIndex;
        }
        else
        {
            break; // heap is good and in order
        }
    }
}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
    // continue until we reach a leaf node
    int leftChild, rightChild, minIndex;

    while (true)
    {
        // calculate the left and right child indices
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        minIndex = index; // assume the current index is the smallest

        // check if the left child exists and has higher priority
        if (leftChild < size && heap[leftChild].priority < heap[minIndex].priority)
        {
            minIndex = leftChild;  
        }

        // check if the right child exists and has higher priority
        if (rightChild < size && heap[rightChild].priority < heap[minIndex].priority)
        {
            minIndex = rightChild;
        }

        // if one of the children are smaller and has higher priority, swap them using logic similar to percolateUp
        if (minIndex != index)
        {
            // swap the current node with the child that has higher priority
            PrinterJob temp = heap[index];
            heap[index] = heap[minIndex];
            heap[minIndex] = temp;

            // move down to the child's index
            index = minIndex;
        }
        else
        {
            break; // heap is good and in order
        }
    }
}

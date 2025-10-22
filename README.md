# MA1-223-Nfergz28
Micro Assignment One for CS 223

Notes:
git status
git add .
git commit -m ""
git push origin main

make
make clean
./priority_queue

Assignment: 
Page
1
of 3
Micro Assignment 3
Heap-Based Priority Queue
Objective
In this micro assignment, you will complete the implementation of a heap-based priority
queue, HeapPriorityQueue, using a fixed-size array of PrinterJob objects. This priority
queue should store PrinterJob instances and maintain a min-heap property (lower number
= higher priority). If you want you can call it rank, instead of priority. Feel free to rename
where necessary.
You are provided with starter code containing the class definitions, a full working
ListPriorityQueue, and a simple REPL (Read-Eval-Print Loop) in main.cpp. Your task is
to implement the missing functionality in HeapPriorityQueue.cpp and ensure that the
code works seamlessly when ListPriorityQueue is commented out and
HeapPriorityQueue is used instead.
Starter Code Overview
You are provided with the following files:
1. PrinterJob.h & PrinterJob.cpp
o Represents a print job with two attributes:
▪ printString: A string representing the document name.
▪ priority: An integer representing the print priority (lower value =
higher priority).
o Includes:
▪ Default constructor (initializes printString to "" and priority to 0).
▪ Parameterized constructor (accepts a string and priority).
▪ Comparison operator < to compare priorities.
2. ListPriorityQueue.h & ListPriorityQueue.cpp
o Implements a linked-list-based priority queue using
std::list<PrinterJob>.
o Contains:
▪ enqueue: Inserts PrinterJob into the list in sorted order.
▪ printJobs: Prints and removes jobs based on priority order.
3. HeapPriorityQueue.h & HeapPriorityQueue.cpp (Your Task)
o Defines a heap-based priority queue that stores PrinterJob objects in a
fixed-size array of 100 elements.
o Your job is to implement:
▪ enqueue: Inserts a job into the heap while maintaining heap order.
▪ printJobs: Removes and prints jobs in priority order.
▪ percolateUp: Ensures heap order when adding a new job.
▪ percolateDown: Ensures heap order when removing the highest
priority job.
4. main.cpp (REPL – Read, Evaluate, Print Loop)
o Allows the user to enqueue jobs and print jobs from the queue.
o Initially, ListPriorityQueue is active:
o Once you finish HeapPriorityQueue, comment out ListPriorityQueue and
uncomment HeapPriorityQueue to test your solution.
5. Makefile (Your Task – Update It)
o The Makefile currently only compiles ListPriorityQueue.
o You must update it to also compile HeapPriorityQueue.
Your Tasks
Complete the missing functionality in HeapPriorityQueue.cpp by implementing the
following methods:
1. void enqueue(const string& str, int priority);
o Inserts a PrinterJob into the heap.
o Maintains heap order using percolateUp.
2. void printJobs();
o Prints jobs in priority order.
o Removes jobs from the heap using percolateDown.
3. void percolateUp(int index);
o Ensures heap order when inserting a new job.
4. void percolateDown(int index);
o Ensures heap order when removing a job.
5. Modify Makefile to compile HeapPriorityQueue
o Ensure HeapPriorityQueue.cpp and HeapPriorityQueue.h are included in
the build process.
o After completion, you should be able to run:
o make
o ./priority_queue
o Your code should work when ListPriorityQueue is commented out and
HeapPriorityQueue is uncommented in main.cpp.
Point Distribution (Total: 100 Points)
Task Points
Correct implementation of enqueue (Maintains heap property using percolateUp) 25
Correct implementation of printJobs (Removes and prints jobs using
percolateDown) 25
Correct implementation of percolateUp (Maintains heap structure on insertion) 15
Task Points
Correct implementation of percolateDown (Maintains heap structure on removal) 15
Correct implementation of the Copy Constructor 5
Correct implementation of the Copy Assignment Operator 5
Modifying Makefile to include HeapPriorityQueue 5
Code Clarity and Style (Proper indentation, meaningful variable names, comments) 5
Important Note on Compilation
• If your code does not compile, you can receive only a maximum of 60 points.
• Ensure that your code compiles successfully before submission to receive full credit.
• While I did my best to provide starter code that only requires you to fill in the missing
pieces, there may be times when you need to add new functions or methods or
edit existing code to get things working. Feel free to make those changes without
affecting the core functionality.
Submission Instructions
• Submit the whole project as a zip file.
Expected Output Example (this screenshot is created using
ListPriorityQueue)
If your HeapPriorityQueue implementation is correct, you should see no difference, and the
jobs will always be printed in priority order (lower number = higher priority), as shown
above. ---END---

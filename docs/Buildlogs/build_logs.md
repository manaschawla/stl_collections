# Build Logs

Session 1
Date: 23-06-2026
Time: 9:30 - 10.30 AM

Goal: 
Goal is to set up the project structure and review the design proposal before starting implementation and created the dynamic_array.h file.

Problems:
Need to understand how malloc/calloc will be used in templates.

What I tried:
I did research about use of malloc and calloc and also discussed the approach with my teammates and tried to find ways how can we implement templates with malloc/calloc.

Outcome:
Created repository folder structure.
Reviewed design proposal.
Listed the function required for dynamic array.
Updated memory management plan to use malloc, realloc and free.
Created initial DynamicArray class.


Session 2
Date: 23-06-2026
Time: 10:45 - 1:00 PM

Goal: 
Goal is to implement the constructor, destructor and some basic operations such as size,capacity and isEmpty functions.These functions are easy and can help in checking the constructor working.

Problems:
Handling the error when there is no free memory in the heap.
fatal error: Dynamic_Array.h: No such file or directory
 #include "Dynamic_Array.h".

what i tried:
I made some research on these as there is also a standard library for these exceptions and discussed with sir also. 
i checked the project folder structure and then understood about the location of header file.
then i updated the include file.

Outcome:
decided to use the library for exceptions.
The header fine was included succesfully.

Session 3
Date: 23-06-2026
Time: 2:00 PM - 3.30 PM

Goal: 
Goal is to implement the element insertion(append) with managing the resizing when the size becomes greater and then impleenting the get set insert remove function.

Problems:
I was confused how to implement the growth factor as 1.5 is a float value and if multiplied type casting would be required.
error: 'out_of_range' is not a member of 'std'


what i tried:
i tried different approaches and check can i implement it using any other operations. i checked the header file and it was not included properly.


Outcome:
I implemented the growth facor using arithmetic and divide operation. I used capacity + capacity/2 as it prevents the float as dive operation automatically gives us the value. the ode wrked successfully.

Session 4
Date: 23-06-2026
Time: 3.40PM - 5.30 PM

Goal: 
the goal is to make dynamic array work for strings and the other data types also.now it i working for primitive data types and generate the copy constructor.

problems: 
error: no matching function for call to placement new
for primitive data types dynamic array was working perfectly but was not working for non-primitive.
And malloc allocates raw memory and does not call constructors but for strings call of constructor and destructor is required.
And how to implement resizing on it.

what i did:
i checked and found we have to include a header file for new.
and for non-primitive data types i studied how strings are stored and how the objects are created and memory is allocaed. Found placement new can be used to create objects into allocated memory.
i created a new memory block and then copied the elements into new one , destroyed the old and then freed old memory.

outcome:
Code compiled successfully for new.
Modifyt he functions so that it can handle non-primitive data types also.
the dynamic array can be now resized safely.

Session 5
Date: 23-06-2026
Time: 8.30 - 10.15 PM

Goal: 
goal is to first create the structure of the node.
the design the basic structure and implement the basic functionalities of the linked list like the constructor, destructor,push front, pushback, get,contains,size,is_empty.

Problem Encountered:
The problem i encountered was to implement the get function as like dynamic array there is no direct indexing.
The other problem is faced is to search the element in the linked list.
When i compiled the linked-list file
error: 'Node' was not declared in this scope
error: expected primary-expression before '>' token

What i did:
I studied how node traversal works and used a temporary pointer starting from the head node. The pointer moves node by node until the required index is reached.
I traversed the list from head to tail and compared each node's data with the target value.
I then reviewed the order of declarations in the header file and found that the LinkedList class was being processed before the Node structure definition.
I checked all declarations using Node<T>. I then found a syntax mistake while declaring a node pointer.

Outcome:
Successfully implemented get() and understood how element access works in a linked structure.
Successfully implemented contains() which returns true if the element exists and false otherwise.
Moved the Node structure before the LinkedList class declaration.
Corrected the template syntax and the code run successfully.


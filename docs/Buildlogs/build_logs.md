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

Session 6
Date: 24-06-2026
Time: 6.30- 8:30AM

Goal:
The goal of this session was to complete the remaining LinkedList functions including insertion, deletion, clear(), Copy Constructor, and Assignment Operator.

Problem Encountered:
While implementing removeBack(), I was unable to directly access the node before the tail.
While implementing insert(), I was confused about where the new node should be connected in the list.
error: 'removeFront' was not declared in this scope

What I Did:
Studied the LinkedList structure and traversed the list until reaching the node just before the tail.
Traversed to the node before the insertion position and carefully updated the next pointers.
Checked the function declarations and definitions and found a mismatch in the function names.

Outcome:
Successfully implemented removeBack() and updated the tail pointer correctly.
Successfully inserted elements at the beginning, middle, and end of the list.
Corrected the function name and the code compiled successfully.

Session 7
Date: 24-06-2026
Time: 2:00 - 4:00 PM

Goal
The goal of this session was to create the basic structure of HashMap. I worked on the Entry structure, hash function, how it will work for the different data types specially for custom data types.Then implement HashMap class design structure.

Problem Encountered
error: 'string' is not a member of 'std'
error: explicit specialization of non-template class
the hash map was able to work only for strings.
The next problem was deciding how to support custom data types.

What I Did
I checked the required header files and found that the string header file was missing.
I studied template syntax and found mistakes in my implementation.
I analyzed the design and did research on different approaches for supporting multiple key types. I then replaced the string hash function with a DefaultHasher template.
I studied and understood how custom classes like Student, Employee etc can be hashed. I designed a DefaultHasher template.

Outcome
I added the required header file.
Corrected the template syntax and successfully created hash functions for int, char, and string data types.
The design became generic and can now support different key types.
It can now be extended for custom data types without changing the main implementation.

Session 7
Date: 24-06-2026
Time: 5:00 - 7:00 PM

Goal:
The goal of this session was to implement the basic HashMap operations. I worked on containsKey(), get(), put() .The main goal was to understand how key value pair work in hash map.

Problems Enountered:
While i was implementing put function, I found that I was not able to update the value of an existing key because LinkedList get function was returning a copy of the data.
While implementing put function, I was confused that how to access the bucket where the key should be stored.
When i was implementing containsKey and get function, I was confused how element would be searched because multiple entries can exist in the same bucket.
While writing put function, I found that I was not able to access and modify the bucket stored inside DynamicArray.

What i did:
I checked the LinkedList file and found that get function was returning T instead of T&. means it was returning the copy instead of actual object.
I studied about hashing and how the index is getting calculated using the hash function.
I researched about separate chaining and traversed the linked list present at the bucket index.I compared each key one by one until required was found.
I checked the dynamic array file,go through the functions and found that the get function in dynamic array was returning copy instead of actual object. I then modified that function.

Outcome:
Modified the get function and return a reference so that the actual data stored in the linked list can be modified directly.
Understood that the hash function returns the bucket index and all operations first calculate the index before searching or inserting data.
Successfully implemented searching in HashMap using linked list traversal.
The HashMap can now directly access the actual bucket stored inside DynamicArray.


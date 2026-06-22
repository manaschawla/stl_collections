# DESIGN PROPOSAL

# Collections Library

## Project Objective

The goal of this project is to build a reusable Collections Library consisting of DynamicArray, LinkedList, and HashMap.

These structures will later be used in Redis Lite and future projects. To make the library reusable with multiple datatypes, templates will be used.

## Design Objectives

- Reusable generic data structures using templates
- Safe memory management through the Rule of Three
- Efficient common operations
- Future extensibility and reuse

## Why Not Use STL?

STL containers already provide similar functionality. However, implementing these structures from scratch helps in understanding memory management, templates, copy semantics, hashing, and performance trade-offs. The goal of this project is basically understanding STL internal implementations.

## Library Structure

```text
Collections Library
│
├── Core Data Structures
│   ├── DynamicArray<T>
│   ├── LinkedList<T>
│   └── HashMap<K,V>
│       └── Uses LinkedList for collision handling
│
├── Common Design Principles
│   ├── Templates
│   ├── Rule of Three
│   └── Deep Copy
│
└── Future Extensions
    ├── Stack<T>
    ├── Queue<T>
    └── Set<T>
```

# 1. Public API

## DynamicArray

DynamicArray stores a pointer to contiguous heap memory along with size and capacity. Initial capacity is 8 and capacity grows by a factor of 1.5 when full.

I choose 8 as intial size because it provides enough space for initial insertions without excessive memory usage and 1.5x growth reduces resizing while keeping memory usage under control.

### Internal architecture

```cpp
T* data;

int size;

int capacity;
```

| Return Type | Method Signature |
|------------|------------------|
| — | DynamicArray() |
| — | DynamicArray(const DynamicArray& other) |
| DynamicArray& | operator=(const DynamicArray& other) |
| — | ~DynamicArray() |
| void | append(const T& value) |
| void | insert(int index, const T& value) |
| void | remove(int index) |
| T | get(int index) const |
| void | set(int index, const T& value) |
| int | size() const |
| int | capacity() const |
| bool | isEmpty() const |
| void | clear() |

![DynamicArray Memory Diagram](images/DynamicArray_Memory_Layout.jpeg)

## LinkedList

LinkedList is implemented as a singly linked list. Each node stores data and a next pointer. Head and tail pointers are maintained.

I chose a singly linked list with head and tail pointers because it uses less memory than a doubly linked list while still allowing efficient insertion at the beginning and end.

### Data Members

```cpp
Node<T>* head;
Node<T>* tail;
int currentSize;
```

| Return Type | Method Signature |
|------------|------------------|
| — | LinkedList() |
| — | LinkedList(const LinkedList& other) |
| LinkedList& | operator=(const LinkedList& other) |
| — | ~LinkedList() |
| void | pushFront(const T& value) |
| void | pushBack(const T& value) |
| void | insert(int index, const T& value) |
| void | removeFront() |
| void | removeBack() |
| void | remove(int index) |
| T | get(int index) const |
| bool | contains(const T& value) const |
| int | size() const |
| bool | isEmpty() const |
| void | clear() |

![LinkedList Memory Diagram](images/LinkedList_Memory_Layout.jpeg)

## HashMap

HashMap uses separate chaining. Each bucket points to a linked list of entries.The initial capacity will be 8 and rehashing will be performed when the load factor becomes greater than 0.75.

I chose 8 as the initial size because it gives enough space at the start without wasting memory. I chose a load factor of 0.75 and doubling during rehashing to keep collisions low and maintain good performance.

### Bucket Node

```cpp
template<typename K, typename V>
struct Entry
{
    K key;
    V value;
    Entry* next;
};
```

### Hash Function Strategy

| Key Type | Hash Method |
|----------|------------|
| Int | key % bucketCount |
| Char | ASCII value % bucketCount |
| String | Polynomial rolling hash |
| Custom Class | User-provided hash function |

| Return Type | Method Signature |
|------------|------------------|
| — | HashMap() |
| — | HashMap(const HashMap& other) |
| HashMap& | operator=(const HashMap& other) |
| — | ~HashMap() |
| void | put(const K& key, const V& value) |
| V | get(const K& key) const |
| bool | contains(const K& key) const |
| void | remove(const K& key) |
| int | size() const |
| bool | isEmpty() const |
| void | clear() |

![DynamicArray Memory Diagram](images/HashMap_Memory_Layout.jpeg)

# 3. Complexity Estimates

| Operation | Best | Average | Worst | Reason |
|-----------|------|----------|--------|--------|
| DynamicArray append() | O(1) | O(1) amortized | O(n) | Resize may copy elements |
| DynamicArray get()/set() | O(1) | O(1) | O(1) | Direct indexing |
| DynamicArray insert()/remove() | O(1) | O(n) | O(n) | Shifting may be required |
| LinkedList pushFront()/pushBack() | O(1) | O(1) | O(1) | Pointer updates |
| LinkedList get() | O(1) | O(n) | O(n) | Traversal required |
| LinkedList insert()/remove()/contains() | O(1) | O(n) | O(n) | Traversal required |
| HashMap put()/get()/contains()/remove() | O(1) | O(1) | O(n) | Many collisions |

# 4 – Design Decisions

## DynamicArray

I selected an initial capacity of 8 and a growth factor of 1.5. This provides a good balance between memory usage and performance. Increasing the capacity by one element at a time was rejected because it would require frequent resizing.

## LinkedList

I selected a singly linked list with head and tail pointers. This design is simple, uses less memory, and supports efficient insertion at both ends. A doubly linked list was not chosen because the extra previous pointer is not required for this project.

## HashMap

I selected separate chaining for collision handling. It is simple to implement and makes insertion and deletion easier. The initial capacity will be 8 and rehashing will be performed when the load factor becomes greater than 0.75. Open addressing was considered but rejected because deletion handling is more complicated.

## Memory Management

Deep copying was selected for all structures to ensure safe memory ownership and to prevent double-free errors.

## Reusability

Templates were selected because they allow the same implementation to work with different data types. This makes the library reusable for future projects.

## Relationship between Structures

| Structure | Role in Library |
|------------|----------------|
| DynamicArray | Sequential storage |
| LinkedList | Node-based storage |
| HashMap | Key-value storage |
| LinkedList | Used by HashMap chains |
| HashMap | Used by Redis Lite |

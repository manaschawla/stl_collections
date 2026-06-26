#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include <new>
#include <stdexcept>

template<typename T>
class DynamicArray
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity);

public:

    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    void append(const T& value);
    void insert(int index, const T& value);
    void remove(int index);
    T& get(int index);
    const T& get(int index) const;
    void set(int index, const T& value);

    int size() const;
    int capacity() const;
    bool isEmpty() const;
    void clear();
};

#include "../../src/DynamicArray/Dynamic_array.tpp"

#endif




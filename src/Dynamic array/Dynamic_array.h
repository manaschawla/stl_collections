#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

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
    void set(int index, const T& value);

    int size() const;
    int capacity() const;
    bool isEmpty() const;
    void clear();
};



template<typename T>
DynamicArray<T>::DynamicArray()
{
    currentSize = 0;
    currentCapacity = 8;

    data = (T*)malloc(currentCapacity * sizeof(T));

    if(data == nullptr)
    {
        throw std::bad_alloc();
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    data = (T*)malloc(currentCapacity * sizeof(T));
    if(data == nullptr)
    {
        throw std::bad_alloc();
    }
    for(int i = 0; i < currentSize; i++)
    {
        new (&data[i]) T(other.data[i]);
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray& other)
{
    if(this == &other)
    {
        return *this;
    }
    for(int i = 0; i < currentSize; i++)
    {
        data[i].~T();
    }
    free(data);
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    data = (T*)malloc(currentCapacity * sizeof(T));
    if(data == nullptr)
    {
        throw std::bad_alloc();
    }
    for(int i = 0; i < currentSize; i++)
    {
        new (&data[i]) T(other.data[i]);
    }
    return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    for(int i = 0; i < currentSize; i++)
    {
        data[i].~T();
    }
    free(data);
}

template<typename T>
int DynamicArray<T>::size() const
{
    return currentSize;
}

template<typename T>
int DynamicArray<T>::capacity() const
{
    return currentCapacity;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const
{
    return currentSize == 0;
}

template<typename T>
void DynamicArray<T>::resize(int newCapacity)
{
    T* newData = (T*)malloc( newCapacity * sizeof(T));
    if(newData == nullptr)
    {
        throw std::bad_alloc();
    }
    for(int i = 0; i < currentSize; i++)
    {
        new (&newData[i]) T(data[i]);
    }
    for(int i = 0; i < currentSize; i++)
    {
        data[i].~T(); 
    }
    free(data);
    data = newData;
    currentCapacity = newCapacity;
}

template<typename T>
void DynamicArray<T>::append(const T& value)
{
    if(currentSize == currentCapacity)
    {
        resize(currentCapacity + currentCapacity / 2);
    }

    new (&data[currentSize]) T(value);

    currentSize++;
}

template<typename T>
T& DynamicArray<T>::get(int index)
{
    if(index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    return data[index];
}

template<typename T>
void DynamicArray<T>::set(int index, const T& value)
{
    if(index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid index");
    }

    data[index] = value;
}

template<typename T>
void DynamicArray<T>::insert(int index, const T& value)
{
    if(index < 0 || index > currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    if(currentSize == currentCapacity)
    {
        resize(currentCapacity + currentCapacity / 2);
    }
    if(currentSize > 0)
    {
        new (&data[currentSize]) T(data[currentSize - 1]);

        for(int i = currentSize - 1; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }
    else
    {
        new (&data[0]) T(value);
    }
    currentSize++;
}

template<typename T>
void DynamicArray<T>::remove(int index)
{
    if(index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    for(int i = index; i < currentSize - 1; i++)
    {
        data[i] = data[i + 1];
    }
    data[currentSize - 1].~T();
    currentSize--;
}

template<typename T>
void DynamicArray<T>::clear()
{
    for(int i = 0; i < currentSize; i++)
    {
        data[i].~T();
    }
    currentSize = 0;
}


#endif
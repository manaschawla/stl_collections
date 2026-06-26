#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdexcept>
#include "../LinkedList/Linked_list.h"
#include "../DynamicArray/Dynamic_array.h"

template<typename K, typename V>
struct Entry
{
    K key;
    V value;

    Entry()
    {
    }

    Entry(
        const K& newKey,
        const V& newValue
    )
    {
        key = newKey;
        value = newValue;
    }
};

template<typename K>
class DefaultHasher
{
public:

    int hash(const K& key,int bucketCount) const
    {
        const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&key);
        unsigned long hash = 0;
        for(int i = 0; i < sizeof(K); i++)
        {
            hash = hash * 31 + bytes[i];
        }
        return hash % bucketCount;
    }
};

template<>
class DefaultHasher<int>
{
public:
    int hash(const int& key,int bucketCount) const
    {
        return (key * 31) % bucketCount;
    }
};

template<>
class DefaultHasher<char>
{
public:
    int hash(const char& key,int bucketCount) const
    {
        return ((int)key) % bucketCount;
    }
};

template<>
class DefaultHasher<long>
{
public:

    int hash(const long& key,int bucketCount) const
    {
        return key % bucketC                                                                                                                                                                                ount;
    }
};

template<>
class DefaultHasher<long long>
{
public:

    int hash(const long long& key,int bucketCount) const
    {
        return key % bucketCount;
    }
};

template<>
class DefaultHasher<float>
{
public:

    int hash(const float& key,int bucketCount) const
    {
        return ((int)(key * 1000)) % bucketCount;
    }
};
template<>
class DefaultHasher<bool>
{
public:

    int hash(const bool& key,int bucketCount) const
    {
        return ((int)key) % bucketCount;
    }
};
template<>
class DefaultHasher<double>
{
public:

    int hash(
        const double& key,
        int bucketCount
    ) const
    {
        return ((long long)(key * 1000000))
               % bucketCount;
    }
};

template<>
class DefaultHasher<std::string>
{
public:
    int hash(
        const std::string& key,
        int bucketCount
    ) const
    {
        unsigned long hash = 0;
        for(int i = 0; i < key.length(); i++)
        {
            hash = hash * 31 + key[i];
        }
        return hash % bucketCount;
    }
};

template<typename K, typename V, typename H = DefaultHasher<K>>
class HashMap
{
private:
    DynamicArray<LinkedList<Entry<K,V>>> buckets;
    int currentSize;
    int bucketCount;
    H hasher;
    void rehash();

public:
    HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);
    void put(const K& key,const V& value);
    V get(const K& key) const;
    bool containsKey(const K& key) const;
    void remove(const K& key);
    void clear();
    int size() const;
    bool isEmpty() const;
};

#include "../../src/HashMap/hash_map.tpp"
#endif
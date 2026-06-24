#include "../Linked List/Linked_list.h"
#include "../Dynamic array/Dynamic_array.h"

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
        return 0;
    }
};

template<>
class DefaultHasher<int>
{
public:
    int hash(const int& key,int bucketCount) const
    {
        return key % bucketCount;
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

template<typename K, typename V>
class HashMap
{
private:
    DynamicArray<LinkedList<Entry<K,V>>> buckets;
    int currentSize;
    int bucketCount;
    DefaultHasher<K> hasher;

public:
    HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);
    ~HashMap();
    void put(const K& key,const V& value);
    V get(const K& key) const;
    bool containsKey(const K& key) const;
    void remove(const K& key);
    void clear();
    int size() const;
    bool isEmpty() const;
};

template<typename K, typename V>
HashMap<K,V>::HashMap()
{
    currentSize = 0;
    bucketCount = 8;

    for(int i = 0; i < bucketCount; i++)
    {
        buckets.append(
            LinkedList<Entry<K,V>>()
        );
    }
}

template<typename K, typename V>
int HashMap<K,V>::size() const
{
    return currentSize;
}

template<typename K, typename V>
bool HashMap<K,V>::isEmpty() const
{
    return currentSize == 0;
}

template<typename K, typename V>
bool HashMap<K,V>::containsKey(const K& key) const
{
    int index = hasher.hash(key,bucketCount);
    LinkedList<Entry<K,V>> bucket = buckets.get(index);
    for(int i = 0; i < bucket.size(); i++)
    {
        Entry<K,V> entry =  bucket.get(i);
        if(entry.key == key)
        {
            return true;
        }
    }
    return false;
}
template<typename K, typename V>
V HashMap<K,V>::get(const K& key) const
{
    int index =hasher.hash(key,bucketCount);
    LinkedList<Entry<K,V>> bucket = buckets.get(index);
    for(int i = 0; i < bucket.size(); i++)
    {
        Entry<K,V> entry =bucket.get(i);
        if(entry.key == key)
        {
            return entry.value;
        }
    }
    throw std::out_of_range(
        "Key not found"
    );
}

template<typename K, typename V>
void HashMap<K,V>::put(const K& key,const V& value)
{
    int index = hasher.hash(key,bucketCount);

    LinkedList<Entry<K,V>>& bucket = buckets.get(index);
    for(int i = 0; i < bucket.size(); i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.get(i).value = value;
            return;
        }
    }
    bucket.pushBack(Entry<K,V>(key,value));
    currentSize++;
}


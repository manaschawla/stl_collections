template<typename K, typename V, typename H>
HashMap<K,V, H>::HashMap()
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

template<typename K, typename V, typename H>
HashMap<K,V, H>::HashMap(const HashMap& other)
{
    buckets = other.buckets;
    currentSize = other.currentSize;
    bucketCount = other.bucketCount;
}

template<typename K, typename V, typename H>
HashMap<K,V, H>& HashMap<K,V, H>::operator=(const HashMap& other)
{
    if(this == &other)
    {
        return *this;
    }
    buckets = other.buckets;
    currentSize = other.currentSize;
    bucketCount = other.bucketCount;
    return *this;
}

template<typename K, typename V, typename H>
int HashMap<K,V, H>::size() const
{
    return currentSize;
}

template<typename K, typename V, typename H>
void HashMap<K,V, H>::rehash()
{
    DynamicArray<LinkedList<Entry<K,V>>> oldBuckets = buckets;
    bucketCount = bucketCount * 2;
    buckets.clear();
    for(int i = 0; i < bucketCount; i++)
    {
        buckets.append(LinkedList<Entry<K,V>>());
    }
    currentSize = 0;
    for(int i = 0; i < oldBuckets.size(); i++)
    {
        LinkedList<Entry<K,V>>& bucket = oldBuckets.get(i);
        for(int j = 0; j < bucket.size(); j++)
        {
            Entry<K,V> entry = bucket.get(j);
            put(entry.key,entry.value);
        }
    }
}

template<typename K, typename V, typename H>
bool HashMap<K,V, H>::isEmpty() const
{
    return currentSize == 0;
}

template<typename K, typename V, typename H>
bool HashMap<K,V, H>::containsKey(const K& key) const
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
template<typename K, typename V, typename H>
V HashMap<K,V, H>::get(const K& key) const
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

template<typename K, typename V, typename H>
void HashMap<K,V, H>::put(const K& key,const V& value)
{
    if(currentSize * 4 >= bucketCount * 3)
    {
        rehash();
    }
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

template<typename K, typename V, typename H>
void HashMap<K,V, H>::remove(const K& key)
{
    int index =hasher.hash(key,bucketCount);
    LinkedList<Entry<K,V>>& bucket = buckets.get(index);
    for(int i = 0; i < bucket.size(); i++)
    {
        if(bucket.get(i).key == key)
        {
            bucket.remove(i);
            currentSize--;
            return;
        }
    }
    throw std::out_of_range("Key not found");
}

template<typename K, typename V, typename H>
void HashMap<K,V, H>::clear()
{
    for(int i = 0; i < bucketCount; i++)
    {
        buckets.get(i).clear();
    }
    currentSize = 0;
}

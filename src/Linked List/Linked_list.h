template<typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& value)
    {
        data = value;
        next = nullptr;
    }
    Node(const T& value, Node<T>* nextNode)
    {
        data = value;
        next = nextNode;
    }
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int currentSize;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();
    void pushFront(const T& value);
    void pushBack(const T& value);
    void insert(int index, const T& value);
    void removeFront();
    void removeBack();
    void remove(int index);
    T get(int index) const;
    bool contains(const T& value) const;
    int size() const;
    bool isEmpty() const;
    void clear();
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

template<typename T>
int LinkedList<T>::size() const
{
    return currentSize;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return currentSize == 0;
}

template<typename T>
void LinkedList<T>::pushFront(const T& value)
{
    Node<T>* newNode =
        new Node<T>(value);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    currentSize++;
}

template<typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node<T>* newNode = new Node<T>(value);

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    currentSize++;
}

template<typename T>
T LinkedList<T>::get(int index) const
{
    if(index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    Node<T>* current = head;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template<typename T>
bool LinkedList<T>::contains(const T& value) const
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        if(current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
template<typename T>
class Node
{
public:
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
    T& get(int index);
    bool contains(const T& value) const;
    int size() const;
    bool isEmpty() const;
    void clear();
    Node<T>* getNode(int index) const;
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
    Node<T>* current = other.head;
    while(current != nullptr)
    {
        pushBack(current->data);

        current = current->next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if(this == &other)
    {
        return *this;
    }
    clear();
    Node<T>* current = other.head;
    while(current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }
    return *this;
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
T& LinkedList<T>::get(int index)
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

template<typename T>
void LinkedList<T>::removeFront()
{
    if(head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    currentSize--;

    if(head == nullptr)
    {
        tail = nullptr;
    }
}

template<typename T>
void LinkedList<T>::removeBack()
{
    if(head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        currentSize--;
        return;
    }
    Node<T>* current = head;
    while(current->next != tail)
    {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    currentSize--;
}

template<typename T>
void LinkedList<T>::remove(int index)
{
    if(index < 0 || index >= currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    if(index == 0)
    {
        removeFront();
        return;
    }
    if(index == currentSize - 1)
    {
        removeBack();
        return;
    }
    Node<T>* current = head;
    for(int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    Node<T>* temp = current->next;
    current->next = temp->next;
    delete temp;
    currentSize--;
}

template<typename T>
void LinkedList<T>::insert(int index,const T& value)
{
    if(index < 0 || index > currentSize)
    {
        throw std::out_of_range("Invalid index");
    }
    if(index == 0)
    {
        pushFront(value);
        return;
    }
    if(index == currentSize)
    {
        pushBack(value);
        return;
    }
    Node<T>* newNode =
        new Node<T>(value);

    Node<T>* current = head;

    for(int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    currentSize++;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    currentSize = 0;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int index) const
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
    return current;
}


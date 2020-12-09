#include <iostream>

using namespace std;

template <class T>
class ListNode
{

private:
    T _data;
    ListNode *_next;
    ListNode *_prev;

public:
    ListNode(T data, ListNode<T> *next, ListNode<T> *prev)
    {
        _data = data;
        _next = next;
        _prev = prev;
    };
    T getData() const { return _data; };
    ListNode *getNext() const { return _next; };
    ListNode *getPrev() const { return _prev; };
    void setNext(ListNode *n) { _next = n; }
    void setPrev(ListNode *p) { _prev = p; }
};

template <class T>
class DoubleLinkedList
{
private:
    ListNode<T> *_first;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool isEmpty();
    bool isFull();
    void insertNode(const T &); //principio
    void addNode(const T &);    //final
    void emit() const;
    void deleteNode(const T &);
    void mutate();
    void operator=(const DoubleLinkedList<T> &);
    ListNode<T> *getFirst() const { return _first; };
    void setFirst(ListNode<T> *f) { _first = f; };
    T sum();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    _first = NULL;
};

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    if (_first)
    {
        ListNode<T> *aux = _first;
        while (aux)
        {
            _first = _first->getNext();
            delete aux;
            aux = _first;
        }
    }
};

template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    if (_first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

template <class T>
void DoubleLinkedList<T>::insertNode(const T &data)
{
    _first = new ListNode<T>(data, _first, NULL);
}

template <class T>
void DoubleLinkedList<T>::addNode(const T &data)
{
    ListNode<T> *aux = _first;

    if (_first)
    {
        while (aux->getNext() != NULL)
        {
            aux = aux->getNext();
        }
        ListNode<T> *aux2 = new ListNode<T>(data, NULL, aux);
        aux->setNext(aux2);
    }
    else
    {
        insertNode(data);
    }
}

template <class T>
void DoubleLinkedList<T>::emit() const
{
    ListNode<T> *aux = _first;
    while (aux)
    {
        cout << aux->getData();
        if (aux->getNext() != NULL)
            cout << " -> ";
        aux = aux->getNext();
    }
    cout << endl;
}

template <class T>
void DoubleLinkedList<T>::deleteNode(const T &value)
{
    ListNode<T> *aux = _first;
    while (aux->getData() != value)
    {
        aux = aux->getNext();
        if (aux == NULL)
            return;
    }

    if (aux == _first)
    {
        _first = _first->getNext();
        _first->setPrev(NULL);
        delete aux;
    }

    else
    {
        ListNode<T> *aux2 = aux->getPrev();
        aux2->setNext(aux->getNext());
        delete aux;
    }
}

template <class T>
void DoubleLinkedList<T>::mutate()
{
    ListNode<T> *aux = _first, *aux2;
    if (_first)
    {
        if (_first->getNext())
        {
            if (_first->getNext()->getNext())
            {
                _first = _first->getNext();
                aux->setNext(_first->getNext());
                aux->setPrev(_first);
                aux2 = _first->getNext();
                aux2->setPrev(aux);
                _first->setNext(aux);
                _first->setPrev(NULL);
            }
            else
            {

                _first = _first->getNext();
                aux->setNext(NULL);
                aux->setPrev(_first);
                _first->setNext(aux);
                _first->setPrev(NULL);
            }
        }
    }
}
template <class T>
void DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &l)
{
    ListNode<T> *aux = l.getFirst(), *aux2 = this->getFirst();
    if (_first)
    {
        while (aux2)
        {
            _first = _first->getNext();
            delete aux2;
            aux2 = _first;
        }
    }
    while (aux)
    {
        this->addNode(aux->getData());
        aux = aux->getNext();
    }
}

template <class T>
T DoubleLinkedList<T>::sum()
{
    ListNode<T> *aux = _first;
    T sum = 0;
    while (aux)
    {
        sum = aux->getData() + sum;
        aux = aux->getNext();
    }
    return sum;
}

template <class T>
DoubleLinkedList<T> mix(DoubleLinkedList<T> &l1, DoubleLinkedList<T> &l2)
{
    ListNode<T> *aux1 = l1.getFirst(), *aux2 = l2.getFirst();
    DoubleLinkedList<T> mixedList;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->getData() >= aux2->getData())
        {
            mixedList.addNode(aux2->getData());
            aux2 = aux2->getNext();
        }
        else
        {
            mixedList.addNode(aux1->getData());
            aux1 = aux1->getNext();
        }
    }

    if (aux1 == NULL)
    {
        while (aux2 != NULL)
        {
            mixedList.addNode(aux2->getData());
            aux2 = aux2->getNext();
        }
    }
    if (aux2 == NULL)
    {

        while (aux1 != NULL)
        {
            mixedList.addNode(aux1->getData());
            aux1 = aux1->getNext();
        }
    }
    return mixedList;
}
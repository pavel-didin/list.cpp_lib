#include "list.h"
#include <stdlib.h>
#include <unistd.h>

template <class T>
ostream &operator << (ostream &out, const List<T> &L)
{
    out << "size: " << L.GetCount() << endl;
    out << "data: ";
    if(L.GetCount())
    {
        Node<T> * node = L.GetHead();
        while(node->next)
        {
            out << node->data << ", ";
            node = node->next;
        }
        out << node->data << endl;
    }
    return out;
};

template <class T>
List<T>::List()
{
    Head = Tail = NULL;
    Count = 0;
}

template <class T>
List<T>::List(const List<T> & L)
{
    Head = Tail = NULL;
    Count = 0;

    Node<T> * node = L.Head;

    while(node)
    {
        AddTail(node->data);
        node = node->next;
    }
}

template <class T>
List<T>::~List()
{
    while(Count)
        Delete(0);
}

template <class T>
void List<T>::AddHead(T item)
{
    Node<T> * node = new Node<T>;

    if (node == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
    }

    node->previous = NULL;

    node->data = item;

    node->next = Head;

    if(Head)
        Head->previous = node;

    Head = node;

    if(Count == 0)
        Tail = node;

    Count++;
}

template <class T>
void List<T>::AddTail(T item)
{
    Node<T> * node = new Node<T>;

    if (node == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
    }

    node->next = NULL;

    node->data = item;

    node->previous = Tail;

    if(Tail)
        Tail->next = node;

    Tail = node;

    if(Count == 0)
        Head = node;

    Count++;
}

template <class T>
void List<T>::Insert(unsigned index, T item)
{

    if(index > Count)
    {
        cerr << "Incorrect position !!!" << endl;
        throw ESIZE;
    }

    if(index == Count)
    {
        AddTail(item);
        return;
    }
    if(index == 0)
    {
        AddHead(item);
        return;
    }

    Node<T> * Ins = Head;

    for(unsigned i = 0; i < index; i++)
    {
        Ins = Ins->next;
    }

    Node<T> * PrevIns = Ins->previous;

    Node<T> * node = new Node<T>;
    if (node == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
    }
    node->data = item;

    PrevIns->next = node;
    node->next = Ins;
    node->previous = PrevIns;
    Ins->previous = node;

    Count++;
}

template <class T>
void List<T>::DeleteFirst()
{
    if(Count == 0)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }
    Node<T> *node = Head;
    Head = Head->next;
    if (Head)
        Head->previous = NULL;
    else
        Tail = NULL;
    delete node;
    Count--;
}

template <class T>
void List<T>::DeleteLast()
{
    if(Count == 0)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }
    Node<T> *node = Tail;
    Tail = Tail->previous;
    if (Tail)
        Tail->next = NULL;
    else
        Head = NULL;
    delete node;
    Count--;
}

template <class T>
void List<T>::Delete(unsigned index)
{
    if(Count == 0)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }
    if(index > Count-1)
    {
        cerr << "Incorrect position !!!" << endl;
        throw ESIZE;
    }

    if(index == Count-1)
    {
        DeleteLast();
        return;
    }

    if(index == 0)
    {
        DeleteFirst();
        return;
    }

    Node<T> * Del = Head;

    for(unsigned i = 0; i < index; i++)
    {
        Del = Del->next;
    }

    Node<T> * PrevDel = Del->previous;
    Node<T> * AfterDel = Del->next;

    PrevDel->next = AfterDel;
    AfterDel->previous = PrevDel;

    delete Del;

    Count--;
}

template <class T>
void List<T>::SetNode(unsigned index, T item)
{
    if(Count == 0)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }
    if(index > Count-1)
    {
        cerr << "Incorrect position !!!" << endl;
        throw ESIZE;
    }

    Node<T> *node = Head;

    for(unsigned i = 0; i < index; i++)
    {
        node = node->next;
    }

    node->data = item;
}

template <class T>
T List<T>::GetNode(unsigned index)
{
    Node<T> *node = Head;

    if(Count == 0)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }

    if(index > Count-1)
    {
        cerr << "Incorrect position !!!" << endl;
        throw ESIZE;
    }

    for(unsigned i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node->data;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & L)
{
    if(this == &L)
        return *this;

    this->~List();

    Node<T> * node = L.Head;

    while(node)
    {
        AddTail(node->data);
        node = node->next;
    }

    return *this;
}

template <class T>
List<T> List<T>::operator + (const List<T>& L)
{
    List Result(*this);

    Node<T> * node = L.Head;

    while(node)
    {
        Result.AddTail(node->data);
        node = node->next;
    }

    return Result;
}

template <class T>
bool List<T>::operator == (const List<T> & L)
{
    if(Count != L.Count)
        return false;

    Node<T> *t1, *t2;

    t1 = Head;
    t2 = L.Head;

    while(t1)
    {
        if(t1->data != t2->data)
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}

template <class T>
bool List<T>::operator != (const List<T> & L)
{
    return !(*this == L);
}

template <class T>
bool List<T>::operator >= (const List<T>& L)
{
    if(Count > L.Count)
        return true;

    if(*this == L)
        return true;

    return false;
}

template <class T>
bool List<T>::operator <= (const List<T>& L)
{
    if(Count < L.Count)
        return true;

    if(*this == L)
        return true;

    return false;
}

template <class T>
bool List<T>::operator > (const List<T>& L)
{
    if(Count > L.Count)
        return true;

    return false;
}

template <class T>
bool List<T>::operator < (const List<T>& L)
{
    if(Count < L.Count)
        return true;

    return false;
}

template <class T>
List<T> List<T>::operator - ()
{
    List Result;

    Node<T> * temp = Head;

    while(temp != 0)
    {
        Result.AddHead(temp->data);
        temp = temp->next;
    }

    return Result;
}

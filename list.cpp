#include "list.h"
#include <stdlib.h>
#include <unistd.h>

#define NOT_FOUND -1

template <class T>
List<T>* List<T>::append(T item)
{
    //create list item
    List<T> *new_item = new List(item);
    if (new_item == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
        return this;
    }
    //new_item->set_item(item);
    //new_item->set_next(NULL);
    //new_item->set_previous(NULL);
    if (this)
    {
        List<T> *list;
        //go to the end
        for (list = this; list->get_next(); list = list->get_next());
        list->set_next(new_item); //append
        new_item->set_previous(list);
    }
    else
    {
        return new_item; //init (create) list
    }
    return this;
}

template <class T>
List<T>* List<T>::add(T item)
{
    //create list item
    List<T> *new_item = new List(item);
    if (new_item == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
        return this;
    }
    //new_item->set_item(item);
    //new_item->set_previous(NULL);
    new_item->set_next(this);
    if (this)
        this->set_previous(new_item);
    return new_item;
}

template <class T>
void List<T>::destroy()
{
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return;
    }
    List<T> *list = this;
    while (list)
    {
        List<T> *list1 = list;
        list = list->get_next();
        delete list1;
    }
}

template <class T>
void List<T>::reverse_print()
{
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
    }
    for ( ; list->get_next(); list = list->get_next());
    for ( ; list; list = list->get_previous())
        cout << list->get_item()<<" ";
    cout << endl;
}

template <class T>
void List<T>::print()
{
    List<T> *list = this;
    for ( ; list; list = list->get_next())
        cout << list->get_item()<<" ";
    cout << endl;
}

template <class T>
List<T>* List<T>::delete_item(unsigned index)
{
    List<T> *list = this;
    unsigned i;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return this;
    }
    for (i = 0; i < index; i++)
    {
        if (!list->get_next())
        {
            cerr << "Invalig size: List" << endl;
            throw ESIZE;
            return this;
        }
        list = list->get_next();
    }
    if (list->get_previous())
        list->get_previous()->set_next(list->get_next());
    else
        list = list->get_next();
    if (list->get_next())
        list->get_next()->set_previous(list->get_previous());
    delete list;
    return this;
}

template <class T>
List<T>* List<T>::delete_first()
{
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return this;
    }
    list = list->get_next();
    if (list)
        list->set_previous(NULL);
    delete this;
    return list;
}

template <class T>
List<T>* List<T>::delete_last()
{
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return this;
    }
    if (!this->get_next())
    {
        delete this;
        return NULL;
    }
    for ( ; list->get_next(); list = list->get_next());
    if (list->get_previous())
        list->get_previous()->set_next(NULL);
    delete list;
    return this;
}

template <class T>
List<T>* List<T>::insert(unsigned index, T item)
{
    List<T> *list = this, *new_item;
    unsigned i;
    if (!this && index)
    {
        cerr << "Invalig size: List" << endl;
        throw ESIZE;
        return this;
    }
    if (!this || !index)
        return add(item);
    for (i = 0; i < index-1; i++)
    {
        list = list->get_next();
        if (!list)
        {
            cerr << "Invalig size: List" << endl;
            throw ESIZE;
            return this;
        }
    }
    new_item = new List(item);
    if (list == NULL)
    {
        cerr << "Not enough memory" << endl;
        throw EMALLOC;
        return this;
    }
    //new_item->set_item(item);
    new_item->set_next(list->get_next());
    new_item->set_previous(list);
    if (list->get_next())
        list->get_next()->set_previous(new_item);
    list->set_next(new_item);
    return this;
}

template <class T>
int List<T>::get(unsigned index)
{
    unsigned i;
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return NOT_FOUND;
    }
    for (i = 0; list; list = list->get_next(), i++)
        if (i == index)
        {
            return list->get_item();
        }
    cerr << "Invalig size: List" << endl;
    throw ESIZE;
    return NOT_FOUND;
}

template <class T>
void List<T>::set(unsigned index, T item)
{
    unsigned i;
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return;
    }
    for (i = 0; list; list = list->get_next(), i++)
        if (i == index)
        {
            list->set_item(item);
            return;
        }
    cerr << "Invalig size: List" << endl;
    throw ESIZE;
}

template<class T>
int List<T>::find(T item)
{
    unsigned i;
    List<T> *list = this;
    if (this == NULL)
    {
        cerr << "List is empty" << endl;
        throw EEMPTY;
        return NOT_FOUND;
    }
    for (i = 0; list; list = list->get_next(), i++)
        if (list->get_item() == item)
        {
            return i;
        }
    cerr << "Not found: List" << endl;
    throw EFOUND;
    return NOT_FOUND;
}

template <class T>
unsigned List<T>::size()
{
    unsigned i;
    List<T> *list = this;
    for(i = 0; list; list = list->get_next(), i++);
    return i;
}

template <class T>
List<T>::List(T new_item)
{
    previous = NULL;
    next = NULL;
    item = new_item;
}

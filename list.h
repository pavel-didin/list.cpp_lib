#ifndef _STACK_H_
#define _STACK_H_

#include <cstring>
#include <iostream>

using namespace std;

template <class T>
class List
{
    T item;
    List<T> *previous;
    List<T> *next;
public:
    enum LIST_ERR
    {
        EMALLOC,
        EFOUND,
        ESIZE,
        EEMPTY
    };

    T get_item() const
    {
        return item;
    }
    List<T> *get_previous()
    {
        return previous;
    }
    List<T> *get_next()
    {
        return next;
    }

    void set_item(T new_item)
    {
        item = new_item;
    }
    void set_previous(List<T> *list)
    {
        previous = list;
    }
    void set_next(List<T> *list)
    {
        next = list;
    }

    List(T new_item);
    //~List();

    List<T> *append(T item);

    List<T> *add(T item);

    void destroy();

    void reverse_print();

    void print();

    List<T> *delete_item(unsigned index);

    List<T> *delete_first();

    List<T> *delete_last();

    List<T> *insert(unsigned index, T item);

    int get(unsigned index);

    void set(unsigned index, T item);

    int find(T item);

    unsigned size();
};

#endif	// _LIST_H_

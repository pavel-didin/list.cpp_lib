#ifndef _LIST_H_
#define _LIST_H_

#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
class List
{
    private:
    struct node;
    node* head, *tail;
    size_t count;
    public:
    List();
    ~List();
    void addToHead(const T&);
    void addToTail(const T&);
    void showFromHead();
    void showFromTail();
    int search(const T&) const;
    void eraseElementByVal(const T&);
    void insert(const size_t&, const T&);
    void sort(const bool& ascending = true);

};


#endif  // _LIST_H_

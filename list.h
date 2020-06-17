#ifndef _LIST_H_
#define _LIST_H_

#include <cstring>
#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node * next, * previous;
};

template <class T>
class List
{
    Node<T> * Head, * Tail;

    unsigned Count;

public:
    enum LIST_ERR
    {
        EEMPTY,
        EMALLOC,
        ESIZE
    };
    // Конструктор
    List();
    // Конструктор копирования
    List(const List&);
    // Деструктор
    ~List();

    // Получить количество элементов
    unsigned GetCount() const { return Count; };
    // Получить голову
    Node<T>* GetHead() const { return Head; };
    // Получить элемент списка
    T GetNode(unsigned);

    // Удалить конкретный элемент
    void Delete(unsigned index);
    //Удалить элемент из начала
    void DeleteFirst();
    //Удалить элемент с конца
    void DeleteLast();
    // Вставить элемент
    void Insert(unsigned index, T item);
    // Добавить элемент в конец списка
    void AddTail(T item);
    // Добавить элемент в начало списка
    void AddHead(T item);
    // Присваивание значение элементу
    void SetNode(unsigned index, T item);

    List& operator = (const List&);
    // сложение двух списков (дописывание)
    List operator + (const List&);

    // сравнение по элементам
    bool operator == (const List&);
    bool operator != (const List&);
    bool operator <= (const List&);
    bool operator >= (const List&);
    bool operator < (const List&);
    bool operator > (const List&);

    // разворот списка
    List operator - ();

    // печать сведений
    template <class T1>
    friend ostream &operator << (ostream &out, const List<T> &L);
};

#endif

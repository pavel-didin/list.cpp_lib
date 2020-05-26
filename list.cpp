#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
struct List<T>::node
{
    T data;
    node* next, *prev;
    node() = default;
    node(const T& val) : data(val), next(NULL), prev(NULL){}
};

template<typename T>
List<T>::List() : head(NULL), tail(NULL), count(0)
{
}

template<typename T>
List<T>::~List()
{
    while(head != NULL)
    {
        node* tmpNewHead = head->next;
        delete head;
        head = tmpNewHead;
    }
    tail = NULL;
    count = 0;
}

template<typename T>
void List<T>::addToHead(const T &val)
{
    node* newNode = new(std::nothrow) node(val);
    if(newNode != NULL)
    {
        if (head == NULL)
        {
            head = tail = newNode;
            head -> next = tail;
            tail ->next = NULL;
            head -> prev = NULL;
        }
        else
        {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    ++count;
}

template<typename T>
void List<T>::showFromHead()
{
    if(head == NULL) return;
    node* tmp = head;
    while(tmp != NULL)
    {
        std::cout<<tmp -> data<<" ";
        tmp = tmp -> next;
    }
    std::cout<<std::endl;
}

template<typename T>
void List<T>::showFromTail()
{
    if(head == NULL) return;
    node* tmp = tail;
    while(tmp != NULL)
    {
        std::cout<<tmp -> data<<" ";
        tmp = tmp -> prev;
    }
    std::cout<<std::endl;
}

template<typename T>
void List<T>::addToTail(const T &val)
{
    node* newNode = new(std::nothrow) node(val);
    if(newNode != NULL)
    {
        if (head == NULL)
        {
            head = tail = newNode;
            head -> next = tail;
            tail ->next = NULL;
            head -> prev = NULL;
        }
        else
        {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    ++count;
}

template<typename T>
int List<T>::search(const T &val) const
{
    if(head == NULL) return -1;
    node* tmp = head;
    size_t pos{0};
    while(tmp != NULL)
    {
        if(tmp -> data == val) return pos;
        tmp = tmp -> next;
        ++pos;
    }
    return -1;
}

template<typename T>
void List<T>::eraseElementByVal(const T& val)
{
   for ( node *current = head; current != NULL; )
   {
       if ( current-> data == val )
       {
           node *tmp = current;
           if( current == tail)
           {
               tail = tail -> prev;
               tail -> next = NULL;
           }
           if ( current->next != NULL )
           {
               current->next->prev = current->prev;
           }

           if ( current->prev != NULL )
           {
               current -> prev -> next = current -> next;
               current = current -> next;
           }
           else
           {
               head = current -> next;
               current = head;
           }
           delete tmp;
           --count;
       }
       else
       {
           current = current->next;
       }
    }
}


template<typename T>
void List<T>::insert(const size_t& pos, const T& val)
{
    if( head == NULL || pos < 0 || pos > count + 1) return;
    if(pos == 0) addToHead(val);
    if(pos == count + 1) addToTail(val);

    node* tmp = head;
    node* newNode = new node(val);
    size_t n{0};
    while(n != pos)
    {
        tmp = tmp -> next;
        ++n;
    }

    tmp -> prev -> next = newNode;
    newNode -> next = tmp;
    newNode -> prev = tmp -> prev;
    tmp -> prev = newNode;
    ++count;

}

template<typename T>
void List<T>::sort(const bool& ascending)
{
     if (head == NULL) return;

   for(int i = 0; i != count; i++)
   {
        node *temp = head;
        while(temp -> next != NULL)
        {
            if(temp -> data > temp -> next -> data)
            {
                T tmpVal = temp -> data;
                temp -> data = temp -> next -> data;
                temp -> next -> data = tmpVal;
            }
            temp = temp -> next;
        }
    }
}

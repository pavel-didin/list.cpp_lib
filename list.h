#ifndef _LIST_H_
#define _LIST_H_

#include <cstring>
#include <iostream>

using namespace std;

typedef class List List;
template <class T>
class list
{
public:
	enum list_error {
		ESUCCESS = 0,
	  EMALLOC,
	  EFOUND,
	  ESIZE
	};

	list();
	~list();

private:
	T item;
	List *previous;
  List *next;
};


#endif  // _LIST_H_

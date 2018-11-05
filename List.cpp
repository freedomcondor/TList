#include "stdlib.h"
#include "stdio.h"

template <class T>
List<T>::List()
{
	head = createNode();
	tail = createNode();
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->next = NULL;
	focal = tail;

	length = 0;
}

template <class T>
List<T>::~List()
{
	Node *p, *q;  
	p = head;
	while (p != NULL)
	{
		q = p->next;
		deleteNode(p);
		p = q;
	}
}

template <class T>
T& List<T>::getFocal()
{
	return focal->data;
}

template <class T>
int List<T>::insert(T x)
{
	Node *p;  

	if (length == 0)
		focal = head;

	p = createNode();
	p->data = x;

	p->next = focal->next;
	p->prev = focal;

	focal->next->prev = p;
	focal->next = p;

	focal = p;

	length++;
	return 0;
}

template <class T>
int List<T>::delFocal()
{
	if (length == 0)
		return -1;

	Node* p = focal;
	focal->prev->next = focal->next;
	focal->next->prev = focal->prev;
	focal = focal->next;

	deleteNode(p);

	length--;
	if ((focal == tail) && (length != 0)) focal = tail->prev;

	return 0;
}


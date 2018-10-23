#include "stdlib.h"
#include "stdio.h"

template <class T>
List<T>::List()
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->next = NULL;
	focal = head;

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
		delete p;
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
	p = (Node*)malloc(sizeof(Node));
	p->data = x;

	p->next = focal->next;
	p->prev = focal;

	focal->next->prev = p;
	focal->next = p;

	focal = p;

	length++;
}

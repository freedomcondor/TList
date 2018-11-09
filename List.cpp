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
	tail->prev = head;
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
int List<T>::moveNextFocal()
{
	if (focal != tail)
	{
		focal = focal->next;
		return 0;
	}
	else
		return -1;
}

template <class T>
int List<T>::movePrevFocal()
{
	if (focal != head)
	{
		focal = focal->prev;
		return 0;
	}
		return -1;
}

template <class T>
int List<T>::moveHeadFocal()
{
	focal = head->next;
	return 0;
}

template <class T>
int List<T>::moveTailFocal()
{
	focal = tail->prev;
	return 0;
}

template <class T>
int List<T>::focalAtHead()
{
	return (focal == head);
}

template <class T>
int List<T>::focalAtTail()
{
	return (focal == tail);
}

template <class T>
int List<T>::pushTail(T x)
{
	Node *temp;

	temp = focal;
	focal = tail;
	insert(x);
	if (length != 1)
		focal = temp;
	return 0;
}

template <class T>
int List<T>::pushHead(T x)
{
	Node *temp;

	temp = focal;
	focal = head;
	insert(x);
	if (length != 1)
		focal = temp;
	return 0;
}

template <class T>
int List<T>::insert(T x)
{
	Node *p;  

	if (focal == tail)
		focal = tail->prev;

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


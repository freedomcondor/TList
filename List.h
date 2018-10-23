#ifndef LIST
#define LIST

template <class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node *next, *prev;
	}*head, *tail, *focal;

public:
	List();
	~List();
	int length;
	int insert(T x);
	int del(T x);
	T& getFocal();
};

#include "List.cpp"
#endif

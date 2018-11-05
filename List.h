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

	Node* createNode()
	{
		Node *p;
		p = new Node();
		return p;
	}
	int deleteNode(Node *p)
	{
		delete p;
		return 0;
	}

public:
	List();
	~List();
	int length;
	T& getFocal();

	int insert(T x);
	int delFocal();
};

#include "List.cpp"
#endif

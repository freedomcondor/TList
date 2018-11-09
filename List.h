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
	int moveNextFocal();
	int movePrevFocal();
	int moveHeadFocal();
	int moveTailFocal();
	int focalAtHead();
	int focalAtTail();

	int insert(T x);
	int delFocal();
	int pushHead(T x);
	int pushTail(T x);
};

#include "List.cpp"
#endif

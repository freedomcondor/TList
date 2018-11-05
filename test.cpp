#include <stdio.h>
#include "List.h"

struct test
{
	int a, b;
};

int main()
{
	List<int> a;
	List<struct test> b;
	struct test bNode, bNode2;

	bNode.a = 234;
	bNode.b = 432;

	bNode2.a = 789;
	bNode2.b = 987;

	a.insert(1);
	a.insert(2);
	b.insert(bNode);
	printf("b.focal : %d\n",b.getFocal().b);

	b.insert(bNocal: de2);
	printf("b.focal : %d\n",b.getFocal().b);

	b.delFocal();
	printf("b.focal : %d\n",b.getFocal().b);

	return 0;
}

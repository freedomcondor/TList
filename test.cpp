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

	bNode2.a = 789;
	bNode2.b = 987;

	printf("-- a empty ------------------------\n");
	for (a.moveHeadFocal(); !a.focalAtTail(); a.moveNextFocal())
		printf("%d\n",a.getFocal());
	printf("--------------------------\n");

	//a.insert(1);
	//a.insert(2);
	a.pushTail(1);
	a.pushTail(2);

	a.pushHead(3);
	a.pushHead(4);

	printf("-- a after insert ------------------------\n");
	for (a.moveHeadFocal(); !a.focalAtTail(); a.moveNextFocal())
		printf("%d\n",a.getFocal());
	printf("--------------------------\n");

	int temp = a.popHead();
	printf("pop = %d\n", temp);
	printf("-- a after pop ------------------------\n");
	for (a.moveHeadFocal(); !a.focalAtTail(); a.moveNextFocal())
		printf("%d\n",a.getFocal());
	printf("--------------------------\n");

	temp = a.popTail();
	printf("pop = %d\n", temp);
	printf("-- a after another pop ------------------------\n");
	for (a.moveHeadFocal(); !a.focalAtTail(); a.moveNextFocal())
		printf("%d\n",a.getFocal());
	printf("--------------------------\n");




	printf("-- b empty ------------------------\n");
	for (b.moveHeadFocal(); !b.focalAtTail(); b.moveNextFocal())
		printf("%d %d\n",b.getFocal().a, b.getFocal().b);
	printf("--------------------------\n");

	b.moveTailFocal();
	b.insert(bNode);

	printf("-- b insert 1 ------------------------\n");
	for (b.moveHeadFocal(); !b.focalAtTail(); b.moveNextFocal())
		printf("%d %d\n",b.getFocal().a, b.getFocal().b);
	printf("--------------------------\n");

	b.moveTailFocal();
	b.insert(bNode2);

	printf("-- b insert 2 ------------------------\n");
	for (b.moveHeadFocal(); !b.focalAtTail(); b.moveNextFocal())
		printf("%d %d\n",b.getFocal().a, b.getFocal().b);
	printf("--------------------------\n");

	b.moveHeadFocal();
	b.delFocal();

	printf("-- b delete 1 ------------------------\n");
	for (b.moveHeadFocal(); !b.focalAtTail(); b.moveNextFocal())
		printf("%d %d\n",b.getFocal().a, b.getFocal().b);
	printf("--------------------------\n");

	return 0;
}

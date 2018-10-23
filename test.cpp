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

	a.insert(1);

	printf("%d\n",a.getFocal());
	printf("%d\n",b.getFocal().b);

	return 0;
}

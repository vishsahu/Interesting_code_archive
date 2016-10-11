#include<stdio.h>
#include<stdlib.h>

int fib(int n);

main()
{
      int n=7;
	  printf("%d\n",fib(n));
	  return 0;
}

int fib(int n)
{
	int *r = malloc(sizeof(int)*n);
	*r++ = 1;
	*r++ = 1;
	for(int i=2;i++<n;)
	{
		*r++ = *(r-1) + *(r-2);
	}
	
	return *--r;
}
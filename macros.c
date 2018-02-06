/*
 * About:
 */
#include <stdio.h>

/* this is correct and recommended macro */
#define SWAP(x, y)		\
	do {				\
		int temp = x;	\
		x = y;			\
		y = temp;		\
	} while (0)			

/* this is bad macro, may fail at expansions */
#define SWAP1(x,y) {	\
	int temp = x;		\
	x = y;				\
	y = temp; }
	
int main(int argc, char* argv[]) {
    int a = 10, b = 20;
	//printf("before a=%d,b=%d\n", a, b);
	SWAP(a,b);
	//printf("after SWAP a=%d,b=%d\n", a, b);
	SWAP1(a,b); // works here
	//printf("after SWAP1 a=%d,b=%d\n", a, b);
	if (1)
		SWAP(a, b);
	//printf("after if SWAP a=%d,b=%d\n", a, b);
	//if (1)
	//	SWAP1(a, b);
	//else // results in compilation error
	//	printf("should not happen\n");
	//printf("after if SWAP1 a=%d,b=%d\n", a, b);
    return 0;
}

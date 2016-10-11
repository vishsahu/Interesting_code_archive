#include <iostream>
#include <stdio.h>
using namespace std;

void print_subsets(int *A, int n) {
    if (n == 0) {
        return;
    }
    int i = 1;
    while (i < n) {
        k = i;
        cnt = 0;
        while (k % 2 == 1) {
            if (k % 2 == 1) {
                printf("A[cnt] ");
                cnt++;
            k = k/2;
        }
    }
    return;
}

int main() {
	// your code goes here
	int n;
	int A[] = {1,2,3};
	n = sizeof(A)/sizeof(int);
	print_subsets(A, n);
	return 0;
}


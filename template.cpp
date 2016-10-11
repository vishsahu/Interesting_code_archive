#include<iostream>
using namespace std;
#include<stdlib.h>
#include <stdio.h>

int main() {
	int i, tc, n;
	long int *A = NULL;
	
    cin >> tc;
    while(tc-- > 0) {
        cin >> n;
		A = (long int *) calloc(n, sizeof(long int));
		for (i = 0; i < n; i++)
			cin >> A[i];
		
		free(A);
	}
}
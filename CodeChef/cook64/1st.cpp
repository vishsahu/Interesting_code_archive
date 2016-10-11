#include<iostream>
using namespace std;
#include<stdlib.h>
#include <stdio.h>

int insert(int i, int val, int *pos, int n, int cl) {
	int x = n-1;
	while (x > i) {
		pos[x] = pos[x-1];
		if(x == i+1)
			pos[x-1] = val;
		x--;
	}
	cl++;
	return cl;
}

int main(){
	int tc, n, i, cl = 0, k = 0, sc = 0;
	int *A = NULL;
	int *pos = NULL;
    cin>>tc;
    while(tc-- >0){
        cin >> n;
		A = (int *) calloc(n, sizeof(int));
		pos = (int *) calloc(n, sizeof(int));
		
		for (k = 0; k < n; k++) {
			pos[k] = -1;
		}
		
		for (i = 0; i < n; i++)
			cin >> A[i];
		
		for (i = 0; i < n; i++) {
			// Pi came
			if(A[i] == 0) {
				sc += cl;
				cl = insert(0, i+1, pos, n, cl);
			}
			else {
				// look for A[i] in pos
				for (k = 0; k < n; k++) {
					if(A[i] == pos[k]) {
						cout << "matched" << k <<" " << endl;
						break;
					}
				}
				if(k < n) {
					if(cl - k >= k) sc += k+1;
					else sc += (cl - k + 1);
					cl = insert(k+1, i+1, pos, n, cl);
				}
				else {
					cl = insert(cl, i+1, pos, n, cl);
				}
					
			}
			
			printf("%d ", A[i]);
			for (k = 0; k < n; k++) {
				printf("%d ", pos[k]);
			}
			printf(" %d %d\n",sc, cl);
		}
		printf("%d\n", sc);
    	free(A);
		free(pos);
	}
}
#include<iostream>
using namespace std;
#include<stdlib.h>
#include <stdio.h>

int main(){
	int id=0, k, tc,n, ans = 0, i;
	long int *A = NULL;
	long int m, sm;
	
    cin>>tc;
    while(tc-- > 0){
        cin >> n;
		A = (long int *) calloc(n, sizeof(int));
		for (i = 0; i < n; i++)
			cin >> A[i];
		
		do {
			m = 0;
			sm = 0;
			for (i = 0; i < n; i++) {
				if (m < A[i]) {
					sm = m;
					m = A[i];
					id = i;
				}
			}
			if(sm == 0) sm = m;
			//cout << m <<" "<< sm << endl;
			A[id] = A[id] - sm;
		} while (m - sm > 0);
		
		for (i = 0; i < n; i++)
			ans += A[i];
		
		cout << ans;
    	free(A);
	}
}
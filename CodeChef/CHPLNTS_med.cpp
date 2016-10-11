#include<stdlib.h>
#include<iostream>
using namespace std;

main()
{
	int n,i,t;
	long long int min, max;
	long long int* h;
	cin >> t;
	while(t-- > 0){
		cin >> n;
		h = (long long int *)calloc(n,sizeof(long long int));
		for (i = 0; i < n; i++) {
			cin >> h[i];
		}
		// code here
		if (n%2 == 0){
			max = h[0] > h[1] ? h[0] : h[1];
			min = h[0] < h[1] ? h[0] : h[1];
			for(i = 2; i < n; i+= 2){
				if(h[i] > h[i+1]){
					max = max > h[i] ? max : h[i];
					min = min < h[i+1] ? min : h[i+1];
				}
				else {
					max = max > h[i+1] ? max : h[i+1];
					min = min < h[i] ? min : h[i];
				}
			}
		}
		else {
			max = h[0];
			min = h[0];
			for(i = 1; i < n; i+= 2){
				if(h[i] > h[i+1]){
					max = max > h[i] ? max : h[i];
					min = min < h[i+1] ? min : h[i+1];
				}
				else {
					max = max > h[i+1] ? max : h[i+1];
					min = min < h[i] ? min : h[i];
				}
			}
		}
		
		cout << max - min << endl;
		free(h);
	}
}
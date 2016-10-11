#include<iostream>
#include<stdlib.h>

using namespace std;
main() {
	int n;
	cout<< " enter the number:"<<endl;
	cin>>n;
	long int * a;
        a = (long int*)calloc((n+1),sizeof(long int));
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = i * a[i-1];	
	}
	cout << "the factorial is " << a[n] << endl;
}

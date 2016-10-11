#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int *);

int main() {
    int n;
    cin>>n;
    int *a;
    a = (int*) malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++) cin >> a[i];
	
    quicksort(a,0,n-1);
    
    for(int i = 0; i < n; i++) cout << a[i] <<" ";
    cout<<endl;
    return 0;
}

void quicksort(int *a, int p, int r) {
	if (p < r) {
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int partition(int *a, int p, int r) {
    int i, j;
    int x = a[r];
    i = p-1;
    for(j = p; j <= r-1; j++){
        if(a[j] <= x) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int *a, int p, int r){
	int q, x = *(a+r);
	int i = -1,j;
	for(int k = 0; k<4;k++){
		cout << *(a+k) <<" ";
	}
	cout << endl;
	for(j=0; j < r; j++){
		if(*(a+j) < x){
			i++;
			*(a+i)  = *(a+i)^*(a+j);
			*(a+j)  = *(a+i)^*(a+j);
			*(a+i)  = *(a+i)^*(a+j);
			}
	}
	*(a+i+1)  = *(a+i+1)^*(a+r);
	*(a+r)  = *(a+i+1)^*(a+r);
	*(a+i+1)  = *(a+i+1)^*(a+r);
	return i+1;
}

void quicksort(int* a, int p, int r){
	int q;
	if(p<r){
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
	return;
}

int main(){
	int size;
	int* a = NULL;
	cin >> size;
	a = (int*)calloc(sizeof(int),size);
	for(int k = 0; k<size;k++){
		cin >> a[k];
	}
	
	for(int k = 0; k<size;k++){
		cout << a[k] <<" ";
	}
	cout << endl;
	
	quicksort(a,0,size-1);
	for(int k = 0; k<size;k++){
		cout << a[k] <<" ";
	}
	cout << endl;
	return 0;
}

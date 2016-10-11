#include<iostream>
#include<string>
using namespace std;
int main(){
	int i, l;
	string a = "abwfkgjkfgdkfkgjkdfhgjfcd";
	l = a.length();
	for(i=0;i<l/2;i++){
		a[i] = a[i]^a[l-i-1];
		a[l-i-1] = a[i]^a[l-i-1];
		a[i] = a[i]^a[l-i-1];
	}
	cout << a << endl;
	return 0;
}
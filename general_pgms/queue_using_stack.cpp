#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

stack<int> s1, s2;

int dequeue(void) {
  int l;
  while(!s1.empty()){
	  s2.push(s1.top());
	  s1.pop();
  }
  l = s2.top();
  s2.pop();
  while(!s2.empty()){
	  s1.push(s2.top());
	  s2.pop();
  }  
  return l;
}

void enqueue(int a){
	s1.push(a);
}
bool isEmpty(){
	return s1.empty();
}

int main() {
	int r;
	enqueue(12);
	enqueue(14);
	enqueue(11);
	r=dequeue(); // should be 12
	cout << r << endl;
	enqueue(9);
	enqueue(89);
	r=dequeue(); //should be 14
	cout << r << endl;
		r=dequeue(); //should be 11
	cout << r << endl;
		r=dequeue(); //should be 9
	cout << r << endl;
		r=dequeue(); //should be 89
	cout << r << endl;
	if(isEmpty()) {
		cout << "empty"<<endl;
	}
	else{
		cout << "not empty"<<endl;
	}
	return 0;  
}
  
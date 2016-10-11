#include<iostream>
using namespace std;
int main(){
	int cnt = 0;
ping:
	cout << ++cnt << " ";
	goto pong;
pong:
	cout << ++cnt << " ";
	if(cnt > 20) goto exit;
	goto ping;
exit:
	return 0;
}
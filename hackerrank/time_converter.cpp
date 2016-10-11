#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
main(){
	char in[10];
	char h[3];
	char middle[7];
	char dn[3];
	int hr, i;
	cin >> in;
	for(int i = 0; i < 2; i++){
		h[i] = in[i];
	}
	h[2] = '\0';
	for(int i = 0; i < 6; i++){
		middle[i] = in[i+2];
	}
	middle[6] = '\0';
	for(int i = 0; i < 2; i++){
		dn[i] = in[i+8];
	} 
	dn[2] = '\0';
	
	hr = atoi(h);
	if(strcmp(dn,"PM")==0){
		if(hr != 12) hr = hr+12;
	}
	else if(strcmp(dn,"AM") == 0 && hr == 12)
		hr = 0;
	printf("%02d%s",hr,middle);
}
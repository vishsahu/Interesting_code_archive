#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>

unsigned long max_of(unsigned long a, unsigned long b)
{
    return a>b?a:b;
}

unsigned long exchange(long n, long* r)
{
    unsigned long q;
    if(r[n-1] >= 0) return (unsigned long)r[n-1];
    if(n<=11) q = n;
    else q = max_of(n,exchange(n/2,r)+exchange(n/3,r)+exchange(n/4,r));
    r[n-1] = q;
    return q;
}

int main(){
    long *r;
    int i;
    long n;
    while(scanf("%ld",&n)!=EOF){
        r = (long*)malloc((n)*sizeof(long));
        for(i=0;i<n;i++) r[i] = -1;
    	cout <<exchange(n,r)<<endl;
    	free(r);
    }
    return 0;
}

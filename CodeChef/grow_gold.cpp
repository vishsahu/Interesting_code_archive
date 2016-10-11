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
    int tc,Init,s1,s2,K,N;
    cin>>tc;
    while(tc-- >0){
        cnt=0;
        cin>>Init>>s1>>s2>>K>>N;
        if(N==1){
            cout<<Init<<endl;
            goto endpt;
        }
        tax_prev = Init;
        for(i=0;i<s1;i++){
            tax_curr = tax_prev + 1;
            if(++cnt + 1 == N){
                cout<<tax_curr<<endl;
                goto endpt;
            }
            tax_prev = tax_curr;
        }
        for(i=0;i<s2;i++){
            tax_curr = tax_prev*2;
            if(++cnt +s1+1 == N){
                cout<<tax_curr<<endl;
                goto endpt;
            }
            tax_prev = tax_curr;
        }
        //K multiplications
    }
    return 0;
}

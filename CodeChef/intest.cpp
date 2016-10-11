#include<iostream>
using namespace std;
#include<stdlib.h>
int main()
{
    unsigned int n, k, num, cnt=0;
    cin>>n>>k;
    while(n-- >0){
        cin>>num;
        if(num%k == 0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

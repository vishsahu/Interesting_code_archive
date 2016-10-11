#include<iostream>
using namespace std;
#include<stdlib.h>

typedef int datatype;
typedef int limit;

limit rand_partition(datatype *a, limit p, limit r)
{
    datatype x = a[r];
    limit i = p-1;
    limit j;
    for(j=p;j<r;j++){
        if(a[j]<a[r]){
            i++;
            std::swap(a[j],a[i]);
        }
    }
    std:swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(datatype *a, limit p, limit r)
{
    if(r>p){
        limit x = (rand() % (r-p+1)) + p;
        std:swap(a[x],a[r]);
        limit q = rand_partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
    return;
}

/*int main()
{
    datatype a[] = {2,1,4543,23,2,3,534,453,34,343,34};
    limit p = 0;
    limit r = sizeof(a)/sizeof(datatype)-1;
    quick_sort(a,p,r);
    for(int i = 0;i<r+1;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}*/



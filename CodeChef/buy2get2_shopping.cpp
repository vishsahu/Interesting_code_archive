#include<iostream>
using namespace std;
#include<stdlib.h>

#include "C:\c_programs\sort_n_search\quick_sort.cpp"

int main(){
    int* item_queue;
    int tc,noi,cost,i;
    cin>>tc;
    while(tc-- >0){
        cost =0;
        cin>>noi;
        item_queue = (int *)calloc(noi,sizeof(int));
        for(i=0;i<noi;i++) cin>>item_queue[i];
        quick_sort(item_queue,0,noi-1);

        for(i = noi-1;i>=0;i=i-4) cost += (item_queue[i]+ ((i>0)? item_queue[i-1]:0));

    	cout <<cost<<endl;
    	free(item_queue);
    }
    return 0;
}

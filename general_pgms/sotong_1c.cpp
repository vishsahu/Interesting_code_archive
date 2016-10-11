// Example program
#include <iostream>
#include <string>

struct node{
    int flag; // 1: indicates node is alive, 0: node is dead
    int key; // contains symbol digit
    int leaf_flag; // indicates if node is leaf node
    node* child[];
};


int main()
{
    int N, K, M, T;
    FILE *fp = fopen("test.txt","w");
    cin>>T; // no of testcases
    for(int i = 1;i<=T;i++){
        cin>>N>>K>>M;// 2<N<4000, 2<K<4000, 1<M<2000
        
        symbols = (*int) calloc(M,sizeof(int));
        for(k=0;k<M;k++){
            // read all forbidden symbols
            cin>>lengthOfSymbol;
            symbols[k] = (int*)calloc(lengthOfSymbol,sizeof(int));

            for(j=0;j<lengthOfSymbol;j++) cin>>*(symbols+k);
            
        };
    
    
    
    // storing forbidden symbols
    
    node* root[K] = {NULL}; // roots ready
    insert(root, x);
    
}

void insert
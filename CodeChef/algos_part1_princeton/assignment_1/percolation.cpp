    #include<stdio.h>
    #include<stdlib.h>
    #include<ctime>
    
    void gen_grid(int n, int** grid)
    {
         for (int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                     *(*(grid+i)+j) = (rand()>>13)&1;
             }
         }
    }
    
    void showgrid(int n, int** grid)
    {
         for (int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                     printf("%d ",*(*(grid+i)+j));
             }
             printf("\n");
         }
    }
    
    int is_full(int i, int j, int** grid, int n)
    {
        if(grid[i][j] == 0) return 0;
        else{
             if(i==0) return 1;
             else{
                  if(is_full(i-1,j,grid,n)) return 1; //top 
                  else if(j>0 & is_full(i,j-1,grid,n)) return 1; // left
                  else if(j<n-1 & is_full(i,j+1,grid,n)) return 1; // right
                  else return 0;
             }
        }
    }
             
    main(int argc, char* argv[])
    {
          srand(time(0));
          int n=atoi(argv[1]);
          int *grid[n];
          for(int r=0;r<n;r++) grid[r] = (int *)malloc(n*sizeof(int));

          gen_grid(n,grid); 
          showgrid(n,grid);
          
          int r = is_full(n-1,0,grid,n);
          if(r) printf("%d, Percolates\n",r);
          else  printf("%d, Does not Percolate\n",r);
          
          free(grid);
    	  return 0;
    }

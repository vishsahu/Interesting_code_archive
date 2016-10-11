    #include<stdio.h>
    main()
    {
          int i,j,k,h,T,N,inside=0,total_circle=0;
          int p[300]={0};
          int xdif1=0,xdif2=0,ydif1=0,ydif2=0;
          float P=0,Q=0,x=0,y=0,r_sq=0,out=0;
          float C[3]={0};
          int x1,y1,x2,y2,x3,y3;
          scanf("%d",&T); // enter the number of test cases
          for(i=0;i<T;i++)
          {
            scanf("%d",&N); // enter number of points in this test case
            for(j=0;j<N;j++)
            {
                scanf("%d %d",&p[j*2],&p[j*2+1]);
            }
          }
          for(i=0;i<2*N;i+=2)
          {
            for(j=i+2;j<2*N;j+=2)
            {
                for(k=j+2;k<2*N;k+=2) // three kill coordinates picked
                {
                    // logic here based on
                    // (p[i],p[i+1])
                    // (p[j],p[j+1])
                    // (p[k],p[k+1])
                    x1=p[i];
                    y1=p[i+1];
                    x2=p[j];
                    y2=p[j+1];
                    x3=p[k];
                    y3=p[k+1];
                    total_circle++;
                    P = ((x1*x1-x2*x2)+(y1*y1-y2*y2))/2;
                    Q = ((x2*x2-x3*x3)+(y2*y2-y3*y3))/2;
                    xdif1 = x1-x2;
                    xdif2 = x2-x3;
                    ydif1 = y1-y2;
                    ydif2 = y2-y3;
                    y = (P*xdif2-Q*xdif1)/(ydif1*xdif2-ydif2*xdif1); // y cocrdiante of center of circle
                    x = (Q - y*ydif2)/xdif2; // x coordinate of center of circle
                    r_sq = (x-x1)*(x-x1)+(y-y1)*(y-y1);
                    C[0] = -2*x;
                    C[1] = -2*y;
                    C[2] = x*x+y*y-r_sq;
                    for(h=0;h<N;h+=2) // scanning the target within or on the circle
                    {
                        if((p[h]*p[h]+p[h+1]*p[h+1]+C[0]*p[h]+C[1]*p[h+1]+C[2])<=0) inside++;
                        else;
                    }
                    inside = inside-3; //excluding the points chosen to form the circle
                }
            }
          }
          out = inside/(total_circle*(N-3));
          printf("\nProbability = %0.2f",out);
          return(0);
    }

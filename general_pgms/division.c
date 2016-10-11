#include<stdio.h>
//#include<conio.h>
main()
{
      int x,y,r,q;
      printf("values of x & y:");
      scanf("%d %d",&x,&y);
      r=x;
      q=0;
      while(r>0)
      {
                r=r-y;
                q++;
      }
      printf("\nFor %d / %d, Quotient = %d % remainder = %d",x,y,q,r);
      //getch();
} 
                

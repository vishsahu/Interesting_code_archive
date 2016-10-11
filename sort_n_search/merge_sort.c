#include<stdio.h>
void swap(int *a, int *b)
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}
main()
{
    int n = 20;
    int a[20] = {0,1,2,3,4,5,6,7,8,9,1,2,6,74,75,89,98,99,100,101};
    int b[20] = {0};
    int i,j=0,k=(n/2);
    for(i=0;i<n;i++)
    {
        //printf("i=%2d,j=%2d,k=%2d, %3d -> ",i,j,k,a[i]);
        if(k==n)            b[i] = a[j++];
        else if(j==(n/2))   b[i] = a[k++];
        else if(a[j]>a[k])  b[i] = a[k++];
        else                b[i] = a[j++];
        //printf("%3d\n",a[i]);
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return(0);
}

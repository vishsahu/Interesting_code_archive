#include<stdio.h>
main()
{
    int a[11]={4,2,6,2,8,12,6,9,45,8,1};
    int j=1,i;
    int key;
    while(j<=11)
    {
        key = a[j];
        for(i=j-1;i>=0;i--)
        {
            if(a[i]>key)
            {
                a[i+1] = a[i];
                a[i] = key; // inserted
            }
            else break;
        }
        j++;
    }
    for(i=0;i<11;i++)
        printf("%d ",a[i]);
    return(0);
}

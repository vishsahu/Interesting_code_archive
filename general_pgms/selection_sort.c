#include<stdio.h>
main()
{
    int a[10] = {0};
    int i,j,temp,n;
    printf("Number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("\n input Array is:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n Sorted array is:\n");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;

}

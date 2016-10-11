#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp;
    char *buffer,n;
    int ret,i;
    fp = fopen("testcase.txt","r");
    if(fp==NULL) printf("ERROR in opening the file\n");

    ret = fread(&n,sizeof(char),3,fp);
    printf("n=%c\n",n);

    buffer = (char*)malloc(sizeof(char)*n*10);
    ret = fread(buffer,sizeof(long int),sizeof(buffer),fp);

    for(i=0;i<100;i++) printf("%c",buffer[i]);
    // code here
    for(i=0;i<n;i++)
    {
        //fact(buffer[i]);
    }
    printf("\n");
    return(0);
}

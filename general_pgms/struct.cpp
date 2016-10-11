#include<iostream>
#include<stdio.h>
struct tr{
int a;
float b;
} asd;
void main()
{
asd.a=120;
asd.b=2.1;
struct tr *ptr; // struct could be omitted in C++ style declaration
ptr=&asd;
printf("%d %f \n",ptr->a,ptr->b);
printf("%d %f \n",asd.a,asd.b);
return 0;
}
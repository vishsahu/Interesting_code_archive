#include<iostream>
#include<stdio.h>
#define DELAY 128000
struct clk{
int hr;
int min;
int sec;
};
void display(struct clk *t); 
void update(struct clk *t);
void delay(void);

void main()
{
clk timer;
timer.sec=0;
timer.min=0;
timer.hr=0;
for(;;)
{
update(&timer);
display(&timer);
delay();
}
return 0;
}

void update(struct clk *t)
{
t->sec++;
if(t->sec==60)
{
t->sec=0;
t->min++;
}
if(t->min==60)
{
t->min=0;
t->hr++;
}
if(t->hr==24) t->hr=0;
}
void display(struct clk *t)
{
printf("%02d:%02d:%02d\n",t->hr,t->min,t->sec);
}
void delay()
{
for(int p=0;p<DELAY;p++);
}
#!/usr/bin/python

count = 0
n=raw_input()
k=raw_input()
n=int(n)
k=int(k)
while (n > 0):
   num = raw_input()
   num = int(num)
   if(num%k == 0) count = count+1
   n=n-1

print count
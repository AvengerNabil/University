#include<stdio.h>
int main(){
char *p,*q,*r,temp;
p=malloc (100);
q=malloc (100);
r=malloc(100);
q=p;
r=p;
gets(p);
while(*q!='\0')
q++;
q--;
while(p<q)
{
    temp=*p;
    *p=*q;
    *q=temp;
    p++;
    q--;
}
puts(r);
}

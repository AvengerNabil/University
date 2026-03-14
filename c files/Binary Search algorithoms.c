#include<stdio.h>
int main (){
int a[]={1,2,3,4,5,6,7,8,9};//Shorted array for binary search
int item=5;
//Runtime Complexity : 0(logN)
//Space Complexity : 0(1)
int left,right,middle;
left=0;right=9;
while(left<=right)
{
    middle=(left+right)/2;
    if (a[middle]==item){
        printf("Item is found at index: %d\n",middle);
        return 0;
    }else if(a[middle]<item){
    left=middle+1;
    }else{
    right=middle-1;
    }
}
printf("Item not found\n");
return 0;
}

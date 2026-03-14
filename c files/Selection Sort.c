//Selection Sort
#include<stdio.h>
int main(){
    int a[]={31,2,5,8,56,44,100};
    int i,j,min_index;
    //outer loop to iterate over all the numbers
    for(i=0;i<7;i++){
        min_index=i;
        //inner loop to fide the minimum index
        for(j=i+1;j<7;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        //swap two numbers(i & min_index)
        int temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
    }
    //Time Complexity: 0(n square)
    //Space Complexity: 0(1)
    //print the sorted array
    for(i=0;i<7;i++){
        printf(" %d ", a[i]);
    }
    printf("\n\n");
    return 0;
}

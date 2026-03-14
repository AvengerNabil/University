#include<stdio.h>
int main(){
int a[]={3,4,5,7,9,10};
int searchItem=10; int i;
//int i;
for (i=0;i<6;i++){
    if(a[i]== searchItem){
        printf("Item is found at index: %d\n", i);
        return 0;
    }
}

printf ("Item not found.\n");

return 0;
}

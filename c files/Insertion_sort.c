//Insertion Sort Algorithoms
#include <stdio.h>
int main() {
    int a[] = {2, 6, 8, 9, 5, 33, 57};
    int i, value, hole;
    for (i = 1; i < 7; i++) {
        value = a[i];
        hole = i;
//Time Complexity: 0(n^2)
//Space Complexity: 0(1)
        while (hole > 0 && a[hole - 1] > value) {
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
    }

    printf("Sorted Array:\n\n");
    for (i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    return 0;
}

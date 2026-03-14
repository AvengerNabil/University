// Bubble Sort - Optimized with Swap Check
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int i, j, size = 5;
    int swap, counter = 0;

//TimeComplexity : 0(n square)
//SpaceComplexity : 0(1)

    for (i = 0; i < size - 1; i++) {
        swap = 0;
        for (j = 0; j < size - 1 - i; j++) {
            counter++;
            if (arr[j] > arr[j + 1]) {
                // Swap two numbers
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        // If no swaps happened, the array is already sorted
        if (swap == 0) {
            break;
        }
    }

    printf("\nAfter sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal loops: %d\n", counter);

    return 0;
}

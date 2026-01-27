#include <stdio.h>

void fifo(int pages[], int n, int frames) {
    int frame[10], fault = 0, index = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            fault++;
        }
    }
    printf("FIFO Page Faults: %d\n", fault);
}

void lru(int pages[], int n, int frames) {
    int frame[10], time[10], fault = 0, counter = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        if (!found) {
            int min = 0;
            for (int j = 1; j < frames; j++)
                if (time[j] < time[min]) min = j;
            counter++;
            frame[min] = pages[i];
            time[min] = counter;
            fault++;
        }
    }
    printf("LRU Page Faults: %d\n", fault);
}

void optimal(int pages[], int n, int frames) {
    int frame[10], fault = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int pos = -1, farthest = i + 1;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) break;
                }
                if (k > farthest) {
                    farthest = k;
                    pos = j;
                }
                if (k == n) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) pos = 0;
            frame[pos] = pages[i];
            fault++;
        }
    }
    printf("Optimal Page Faults: %d\n", fault);
}

int main() {
    int pages[20], n, frames, choice;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    while (1) {
        printf("\n1. FIFO\n2. LRU\n3. Optimal\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: fifo(pages, n, frames); break;
            case 2: lru(pages, n, frames); break;
            case 3: optimal(pages, n, frames); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

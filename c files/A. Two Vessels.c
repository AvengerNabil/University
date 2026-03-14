#include <stdio.h>
#include <stdlib.h>  // For abs()
#include <math.h>    // For ceil()

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int diff = abs(a - b);
        int moves = (diff + c + c - 1) / (2 * c);  // Equivalent to ceil(diff / (2*c))
        printf("%d\n", moves);
    }

    return 0;
}
//A. Two Vessels-https://codeforces.com/problemset/problem/1872/A

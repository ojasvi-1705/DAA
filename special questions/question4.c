//Given an integer n, return true if it is a power of two.
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("%d is a power of two.\n", n);
    else
        printf("%d is NOT a power of two.\n", n);

    return 0;
}

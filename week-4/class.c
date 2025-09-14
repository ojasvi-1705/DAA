#include <stdio.h>
#include <time.h>

int power1(int x, int y) {
    int f = 1;
    for (int i = 1; i <= y; i++) {
        f = f * x;
    }
    return f;
}


int power2(int x, unsigned int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {         // if y is odd
            res = res * x;
        }
        y = y >> 1;          // divide y by 2
        x = x * x;
    }
    return res;
}


int isArmstrong(int n, int method) {
    if (n == 0) return 1;

    int temp = n, sum = 0, digits = 0;

    // count digits
    int t = n;
    while (t != 0) {
        digits++;
        t /= 10;
    }

    // calculate sum of powers of digits
    while (temp != 0) {
        int rem = temp % 10;
        if (method == 1) {
            sum += power1(rem, digits);
        } else {
            sum += power2(rem, digits);
        }
        temp /= 10;
    }

    return (sum == n);
}


int main() {
    int ranges[] = {10, 100, 1000, 10000, 100000};
    int size = sizeof(ranges) / sizeof(ranges[0]);

    int REPEAT = 1000;  

    for (int m = 1; m <= 2; m++) {
        printf("\n=== Method %d ===\n", m);
        for (int r = 0; r < size; r++) {
            clock_t start = clock();

            for (int rep = 0; rep < REPEAT; rep++) {
                for (int n = 0; n <= ranges[r]; n++) {
                    isArmstrong(n, m);
                }
            }

            clock_t end = clock();
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

            // average time for single run
            time_taken = time_taken / REPEAT;

            printf("Range 0-%d: %f seconds\n", ranges[r], time_taken);
        }
    }

    return 0;
}
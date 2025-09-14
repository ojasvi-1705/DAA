//Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find the missing one.

#include <stdio.h>

int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2; // expected sum
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return total - sum; // missing number
}

int main() {
    int arr[] = {3, 0, 1}; // example
    int n = sizeof(arr) / sizeof(arr[0]); 

    int missing = findMissing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}

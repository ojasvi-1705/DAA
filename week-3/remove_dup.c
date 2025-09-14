#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if(n == 0) return 0;
    int res = 1; 
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[res-1]) {
            arr[res++] = arr[i];
        }
    }
    return res;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int newLength = removeDuplicates(arr, n);
    for(int i = 0; i < newLength; i++) printf("%d ", arr[i]);
    return 0;
}

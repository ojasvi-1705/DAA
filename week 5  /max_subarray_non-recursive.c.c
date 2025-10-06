#include <stdio.h>

int main() {
    int arr[] = {3,5,1,8,2};
    int n = 5;
    int l = 1, r = 3;
    int max = arr[l], min = arr[l];

    for(int i = l; i <= r; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("%d %d\n", max, min);
    return 0;
}


#include <stdio.h>

void findMaxMin(int arr[], int l, int r, int *max, int *min){
    if(l > r) return;
    if(arr[l] > *max) *max = arr[l];
    if(arr[l] < *min) *min = arr[l];
    findMaxMin(arr, l+1, r, max, min);
}

int main(){
    int arr[] = {3,5,1,8,2};
    int l = 1, r = 3;
    int max = arr[l], min = arr[l];
    findMaxMin(arr, l, r, &max, &min);
    printf("%d %d\n", max, min);
    return 0;
}

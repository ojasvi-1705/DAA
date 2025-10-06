#include <stdio.h>

void findMaxMinDC(int arr[], int l, int r, int *max, int *min){
    if(l == r){
        *max = arr[l];
        *min = arr[l];
        return;
    }
    int mid = (l + r)/2;
    int max1, min1, max2, min2;
    findMaxMinDC(arr, l, mid, &max1, &min1);
    findMaxMinDC(arr, mid+1, r, &max2, &min2);
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main(){
    int arr[] = {3,5,1,8,2};
    int l = 1, r = 3;
    int max, min;
    findMaxMinDC(arr, l, r, &max, &min);
    printf("%d %d\n", max, min);
    return 0;
}

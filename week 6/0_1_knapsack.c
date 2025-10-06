#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
   
    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] > W)
        return knapsack(W, wt, val, n-1);
    else {
        int include = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1);
        int exclude = knapsack(W, wt, val, n-1);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int val[] = {16, 19, 23, 28};
    int wt[]  = {2, 3, 4, 5};
    int W = 7;
    int n = sizeof(val)/sizeof(val[0]);

    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}

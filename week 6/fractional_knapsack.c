#include <stdio.h>

int main() {
    int n;
    float weight[20], value[20], ratio[20];
    float capacity, temp, totalValue = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &value[i]);
        ratio[i] = value[i] / weight[i];
    }

    scanf("%f", &capacity);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }

    float remaining = capacity;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            totalValue += value[i];
            remaining -= weight[i];
        } else {
            totalValue += ratio[i] * remaining;
            break;
        }
    }

    printf("%.2f\n", totalValue);

    return 0;
}

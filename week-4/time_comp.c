#include <stdio.h>
#include <time.h>

// -------- Bubble Sort --------
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// -------- Selection Sort --------
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// -------- Insertion Sort --------
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// -------- Utility Function --------
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// -------- Main --------
int main() {
    int n = 5000;   // try changing size for larger input
    int arr[n], arr1[n], arr2[n], arr3[n];

    // Fill array with descending numbers (worst case for insertion sort)
    for (int i = 0; i < n; i++)
        arr[i] = n - i;

    clock_t start, end;
    double time_taken;

    // Bubble Sort
    copyArray(arr, arr1, n);
    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took: %f seconds\n", time_taken);

    // Selection Sort
    copyArray(arr, arr2, n);
    start = clock();
    selectionSort(arr2, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took: %f seconds\n", time_taken);

    // Insertion Sort
    copyArray(arr, arr3, n);
    start = clock();
    insertionSort(arr3, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took: %f seconds\n", time_taken);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}
int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    int count = sizeof(sizes) / sizeof(sizes[0]);
    printf("Array Size\tInsertion Sort (sec)\tBubble Sort (sec)\n");
    for (int s = 0; s < count; s++) {
        int n = sizes[s];
        int *original = (int*)malloc(n * sizeof(int));
        int *a = (int*)malloc(n * sizeof(int));
        int *b = (int*)malloc(n * sizeof(int));
        if (original == NULL || a == NULL || b == NULL) {
            printf("Memory allocation failed.\n");
            free(original);
            free(a);
            free(b);
            return 1;
        }
        srand(42);
        for (int i = 0; i < n; i++)
            original[i] = rand();
        for (int i = 0; i < n; i++) {
            a[i] = original[i];
            b[i] = original[i];
        }
        clock_t start = clock();
        insertionSort(a, n);
        clock_t end = clock();
        double insertionTime = (double)(end - start) / CLOCKS_PER_SEC;
        start = clock();
        bubbleSort(b, n);

end = clock();
        double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t\t%.6f\t\t%.6f\n", n, insertionTime, bubbleTime);
        free(original);
        free(a);
        free(b);
    }
    return 0;
}

#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n], pos[n], neg[n];
    int p = 0, q = 0;
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0)
            pos[p++] = arr[i];
        else
            neg[q++] = arr[i];
    }
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < p)
        arr[k++] = pos[i++];
    while (j < q)
        arr[k++] = neg[j++];
    printf("Rearranged array:\n");
    for (int x = 0; x < n; x++)
        printf("%d ", arr[x]);
    return 0;
}

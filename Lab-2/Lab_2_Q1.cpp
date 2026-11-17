#include <stdio.h>
int main() {
    int n, capacity, choice, index, value;
    printf("Enter maximum capacity: ");
    scanf("%d", &capacity);
    printf("Enter current size of array: ");
    scanf("%d", &n);
    if (n < 0 || n > capacity) {
        printf("Invalid array size");
        return 0;
    }
    int arr[capacity];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter 1 to insert or 2 to delete: ");
    scanf("%d", &choice);
    printf("Enter index (starts from 0): ");
    scanf("%d", &index);
    if (choice == 1) {
        if (n == capacity) {
            printf("Overflow");
            return 0;
        }
        if (index < 0 || index > n) {
            printf("Invalid index");
            return 0;
        }
        printf("Enter element to insert: ");
        scanf("%d", &value);
        for (int i = n; i > index; i--)
            arr[i] = arr[i - 1];
        arr[index] = value;
        n++;
    } else if (choice == 2) {
        if (n == 0) {
            printf("Underflow");
            return 0;
        }
        if (index < 0 || index >= n) {
            printf("Invalid index");
            return 0;
        }
        for (int i = index; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    } else {
        printf("Invalid choice");
        return 0;
    }
    printf("Array after operation:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Second largest and second smallest do not exist.");
        return 0;
    }
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }
    if (secondLargest == INT_MIN || secondSmallest == INT_MAX) {
        printf("Second largest or second smallest does not exist.");
        return 0;
    }
    printf("Second largest = %d\n", secondLargest);
    printf("Second smallest = %d\n", secondSmallest);
    return 0;
}

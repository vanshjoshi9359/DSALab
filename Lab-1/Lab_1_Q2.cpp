#include <stdio.h>
void printSubsets(int arr[], int n, int index, int target,
                  int subset[], int size, int sum) {
    if (index == n) {
        if (sum == target) {
            printf("{ ");
            for (int i = 0; i < size; i++)
                printf("%d ", subset[i]);
            printf("}\n");
        }
        return;
    }
    subset[size] = arr[index];
    printSubsets(arr, n, index + 1, target,
                 subset, size + 1, sum + arr[index]);
    printSubsets(arr, n, index + 1, target,
                 subset, size, sum);
}
int main() {
    int n, target;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n], subset[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the required sum: ");
    scanf("%d", &target);
    printf("Subsets with sum %d:\n", target);
    printSubsets(arr, n, 0, target, subset, 0, 0);
    return 0;
}

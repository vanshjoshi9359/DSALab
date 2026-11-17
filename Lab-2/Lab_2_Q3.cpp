#include <stdio.h>
int main() {
    int m, n;
    printf("Enter dimensions of matrix (m n): ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    int count = 0;
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                count++;
        }
    }
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\nSparse Matrix (Row Column Value):\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
        }
    }
    return 0;
}

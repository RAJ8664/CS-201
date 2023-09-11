#include <stdio.h>

int main() {
    int rows, cols;
	scanf("%d%d",&rows,&cols);

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int k = 0; k < rows + cols - 1; k++) {
        if (k < rows) {
            for (int i = k, j = 0; i >= 0 && j < cols; i--, j++) {
                printf("%d ", matrix[i][j]);
            }
        } 
        else {
            for (int i = rows - 1, j = k - rows + 1; i >= 0 && j < cols; i--, j++) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

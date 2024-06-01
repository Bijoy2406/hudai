#include <stdio.h>
#include <stdlib.h>


int** two_d(int *ara, int n, int *total_rows, int *sizes_of_each_row) {
    int **ara2d = (int**)malloc(sizeof(int*));
    int row = 0, col = 0;
    *(ara2d + row) = (int*)malloc(sizeof(int));
    for(int i = 0; i < n; i++) {
        if(*(ara + i) == -1) {
            *(sizes_of_each_row + row) = col;
            row++;
            ara2d = (int**)realloc(ara2d, (row+1)*sizeof(int*));
            *(ara2d + row) = (int*)malloc(sizeof(int));
            col = 0;
        } else {
            *(*(ara2d + row) + col) = *(ara + i);
            col++;
            *(ara2d + row) = (int*)realloc(*(ara2d + row), (col+1)*sizeof(int));
        }
    }
    *(sizes_of_each_row + row) = col;
    *total_rows = row + 1;
    return ara2d;
}
int check(int *ara, int n) {
    if(*ara == -1 || *(ara + n - 1) == -1) {
        return 0;
    }
    for(int i = 0; i < n - 1; i++) {
        if(*(ara + i) == -1 && *(ara + i + 1) == -1) {
            return 0;
        }
    }
    return 1;
}


void Printing2D(int **ara2d, int *sizes_of_each_row, int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < *(sizes_of_each_row + i); j++) {
            printf("%d ", *(*(ara2d + i) + j));
        }
        printf("\n");
    }
}

void sorting2D(int **ara2d, int *sizes_of_each_row, int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < *(sizes_of_each_row + i); j++) {
            for(int k = j+1; k < *(sizes_of_each_row + i); k++) {
                if(*(*(ara2d + i) + j) > *(*(ara2d + i) + k)) {
                    int temp = *(*(ara2d + i) + j);
                    *(*(ara2d + i) + j) = *(*(ara2d + i) + k);
                    *(*(ara2d + i) + k) = temp;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the 1D array: ");
    scanf("%d", &n);

    int *ara = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the 1D array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", ara + i);
    }

    if(!check(ara, n)) {
        printf("Invalid input. -1 cannot be the 1st or last element of the array. Also -1 cannot occur side by side inside the array.\n");
        free(ara);
        return 0;
    }

    int total_rows = 0;
    int *sizes_of_each_row = (int*)malloc(sizeof(int));
    int **ara2d = two_d(ara, n, &total_rows, sizes_of_each_row);

    printf("Generated 2D array:\n");
    Printing2D(ara2d, sizes_of_each_row, total_rows);

    sorting2D(ara2d, sizes_of_each_row, total_rows);

    printf("After Sorting:\n");
    Printing2D(ara2d, sizes_of_each_row, total_rows);

    for(int i = 0; i < total_rows; i++) {
        free(*(ara2d + i));
    }
    free(ara2d);
    free(sizes_of_each_row);
    free(ara);

    return 0;
}

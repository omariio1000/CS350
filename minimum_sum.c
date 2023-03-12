#include <stdio.h>
#include <stdlib.h>

int min(int n);
void init();

int n = 4;
int **triangle;

int main(void) {
    triangle = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) triangle[i] = (int*) calloc(n, sizeof(int));
    init(triangle);

    printf("The smallest sum is %d\n", min(n));

    return 0;
}

int min(int n) {
    int **res;
    res = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) res[i] = (int*) calloc(n, sizeof(int));
    init(res);

    for (int row = n - 2; row >= 0; row--) {
        for (int column = 0; column < row + 1; column++) {
            
            int leftIdx = column;
            int rightIdx = leftIdx + 1;

            if (rightIdx > n - 1) res[row][column] += res[row + 1][rightIdx];
            else if (res[row + 1][rightIdx] > res[row + 1][leftIdx]) res[row][column] += res[row + 1][leftIdx];
            else res[row][column] += res[row + 1][rightIdx];

            printf("The value of res[%d][%d] is %d\n", row, column, res[row][column]);


        }
        printf("\n");
    }
    return res[0][0];
}

void init(int **t) {
    t[0][0] = 2;

    t[1][0] = 5;
    t[1][1] = 4;

    t[2][0] = 1;
    t[2][1] = 4;
    t[2][2] = 7;

    t[3][0] = 8;
    t[3][1] = 6;
    t[3][2] = 9;
    t[3][3] = 6;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int f();
int **board;
int **t;
int n = 5;
int m = 4;

int main(void) {

    board = (int**) calloc(n + 1, sizeof(int*));
    t = (int**) calloc(n + 1, sizeof(int*));
    for (int i = 0; i < n + 1; i++) board[i] = (int*) calloc(m + 1, sizeof(int));
    for (int i = 0; i < n + 1; i++) t[i] = (int*) calloc(m + 1, sizeof(int));
    board[1][2] = board[2][2] = board[2][4] = board [3][1] = board [3][3] = board[4][4] 
        = board[5][2] = board [5][3] = board[5][4] = 1;

    printf("Maximum amount of pebbles is %d\n", f());
    return EXIT_SUCCESS;
}

int f() {
    for (int r = 1; r < m + 1; r++) {
        for (int c = 1; c < n + 1; c++) {
            int a = t[r][c - 1];
            int b = t[r - 1][c];
            int max = a;
            if (b > a) max = b;
            t[r][c] = board[r][c] + max;
        }
    }

    return t[m + 1][n + 1];
}
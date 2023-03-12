#include <stdio.h>
#include <stdlib.h>

int nCk(int n, int k);
int fact(int num);
void init();

int n = 5;
int k = 3;
int **f;

int main(void) {
    f = (int**) calloc(n + 1, sizeof(int*));
    for (int i = 0; i < n + 1; i++) f[i] = (int*) calloc(k + 1, sizeof(int));
    init();
    
    printf("%d-Choose-%d is %d\n", n, k, nCk(n, k));

    return 0;
}

int nCk(int n, int k) {
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (f[i][j] == -1) {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
            printf("f[%d][%d] = %d\t", i, j, f[i][j]);
        }
        printf("\n");
    }

    return f[n][k];
}

int fact(int num) {
    int ret = 1;
    for (int i = 1; i <= num; i++) ret *= i;
    return ret;
}

void init() {
    for (int i = 0; i < n + 1; i++) {
        for(int j = 0; j < k + 1; j++) {
            if (i == j) f[i][j] = 1;
            else if (j == 1) f[i][j] = i;
            else if (j > i) f[i][j] = 0;
            else f[i][j] = -1;
        }
    }
}
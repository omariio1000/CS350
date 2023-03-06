#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int f(int n);
int f2(int n);
int *t;

int main (void) {
    int coins = 0;
    printf("Input number of coins: ");
    scanf("%d", &coins);
    t = (int*) malloc(sizeof(int) * coins);
    for (int i = 0; i < coins; i++) t[i] = -1;
    int coinsReq = f2(coins);
    printf("Minimum number of coins is %d\n", coinsReq);
    free(t);
    t = NULL;
    return EXIT_SUCCESS;
}

int f(int n) {
    if (n == 1 || n == 3 || n == 4) return 1;
    if (n == 2) return 2;
    int a = f(n - 4);
    int b = f(n - 3);
    int c = f(n - 1);
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    
    return 1 + min;
}

int f2(int n) {
    if (n == 1 || n == 2 || n == 3 || n == 4) return t[n];

    for (int k = 5; k <= n; k++) {
        int a = t[k - 1];
        int b = t[k - 3];
        int c = t[k - 4];
        int min = a;
        if (b < min) min = b;
        if (c < min) min = c;

        t[k] = 1 + min;
    }
    return t[n];
}
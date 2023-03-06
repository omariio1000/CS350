#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int f(int n);

int main (void) {
    int coins = 0;
    printf("Input number of coins: ");
    scanf("%d", &coins);
    int coinsReq = f(coins);
    printf("Minimum number of coins is %d\n", coinsReq);
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
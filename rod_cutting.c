#include <stdio.h>
#include <stdlib.h>

int rodCut(int n);
void init();

int n = 8;
int *p;

int main(void) {
    p = (int*) calloc(n, sizeof(int));
    init();

    printf("The maximum sale price is %d\n", rodCut(n));

    return 0;
}

int rodCut(int n) {
    int *res = (int*) calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        int max = -1;
        for (int j = 0; j < i; j++) if (p[j] + res[i - j - 1] > max) max =  p[j] + res[i - j - 1];
        res[i] = max;
    }

    return res[n];
}

void init() {
    p[0] = 1;
    p[1] = 5;
    p[2] = 8;
    p[3] = 9;
    p[4] = 10;
    p[5] = 17;
    p[6] = 17;
    p[7] = 20;
}
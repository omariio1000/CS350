#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//cc merge_sort.c -lm
//to change: cc merge_sort.c -lm -DMAX=1000 (not implemented)

/*
#ifndef MAX
    #define MAX 100
#endif
*/

int main(void) {
    int n;
    srandom(time(NULL));
    printf("Array length: ");
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) x[i] = floor(random() % n); // floor(random()%n);
    printf("UNSORTED:\t");
    for (int i = 0; i < n; i++)printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");
    
    

    printf("SORTED:\t\t");
    for (int i = 0; i < n; i++) printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    return EXIT_SUCCESS;
}

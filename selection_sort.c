#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//cc merge_sort.c -lm
//to change: cc merge_sort.c -lm -DMAX=1000 -Dn=25

#ifndef n
    #define n 20
#endif

#ifndef MAX
    #define MAX 100
#endif

int x[n];


int main(void) {
    srandom(time(NULL));
    for (int i = 0; i < n; i++) x[i] = floor(random() % MAX);
    printf("UNSORTED:\t");
    for (int i = 0; i < n; i++)printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");
    
    for (int i = 0; i < n; i++) {
        int smallestNumber = x[i];
        int smallestIndex = i;
        for (int j = i; j < n; j++) {
            if (x[j] < smallestNumber) {
                smallestNumber = x[j];
                smallestIndex = j;
            }
        }
        int temp = x[smallestIndex];
        x[smallestIndex] = x[i];
        x[i] = temp;
    }

    printf("SORTED:\t\t");
    for (int i = 0; i < n; i++) printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    return EXIT_SUCCESS;
}

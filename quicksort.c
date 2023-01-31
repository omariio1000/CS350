#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
cc quicksort.c -lm
by default uses input.txt
to change file: -DfileName=\"filename.txt\"
to random gen: -DFILE_INPUT=0
can change random gen vals with -Dn, and -DMAX
*/

#ifndef n
    #define n 10
#endif

#ifndef fileName
    #define fileName "input.txt"
#endif

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 1024
#endif

#ifndef MAX
    #define MAX 1000
#endif

#ifndef FILE_INPUT
    #define FILE_INPUT 1
#endif

int x[n];
char buf[BUFFER_SIZE] = {0};
FILE *file = NULL;

void readFile();
void randomGen();
void quickSort(int low, int high);

int main(void) {
    if (FILE_INPUT) readFile();
    else randomGen();

    printf("INITIAL:\t");
    for (int i = 0; i < n; i++)printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    quickSort(0, n-1);

    printf("SORTED:\t\t");
    for (int i = 0; i < n; i++) printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    return EXIT_SUCCESS;
}

void readFile() {
    file = fopen(fileName, "r");
    if (!file) exit(1);
    int i = 0;
    while (fgets(buf, 1024, file)) {
        sscanf(buf, "%d", &x[i]);
        i++;
    }
}

void randomGen() {
    srandom(time(NULL));
    for (int i = 0; i < n; i++) x[i] = floor(random() % MAX);
}

void quickSort(int low, int high) {
    if (low == high) return;
    int middle = low + (high - low) / 2;
    int pivot = x[low];
    int l_ptr = low; 
    int r_ptr = high;
    while (l_ptr <= r_ptr) {
        while (x[l_ptr] < pivot) l_ptr++;
        while (x[r_ptr] > pivot) r_ptr--;

        if (l_ptr <= r_ptr) {
            int temp = x[l_ptr];
            x[l_ptr] = x[r_ptr];
            x[r_ptr] = temp;
            l_ptr++;
            r_ptr--;
        }
    }
    if (low < r_ptr) quickSort(low, r_ptr);
    if (high > l_ptr) quickSort(l_ptr, high);
}
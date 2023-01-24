#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//cc merge_sort.c -lm

#ifndef n
    #define n 9
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
void mergeSort(int low, int high);
void merge();

int main(void) {
    if (FILE_INPUT) readFile();
    else randomGen();
    
    printf("INITIAL:\t");
    for (int i = 0; i < n; i++)printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    mergeSort(0, n-1);

    printf("SORTED:\t\t");
    for (int i = 0; i < n; i++) printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    return EXIT_SUCCESS;
}

void readFile() {
    file = fopen(fileName, "r");
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

void mergeSort(int low, int high) {
    int mid = (low + high ) / 2;

    if (low == high) return; //base case    

    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    
    merge(low, mid, high);
}

void merge(int low, int mid, int high) {
    int len = high - low + 1;

    /*
    printf("\n-----------\nLOW: %d, MID: %d, HIGH: %d", low, mid, high);
    printf("\nCURRENT ARRAY: ");
    for (int i = low; i <= high; i++) printf("%d ", x[i]);
    printf("\nLEFT SIDE: ");
    for (int i = low; i <= mid; i++) printf("\t%d", x[i]);
    printf("\nRIGHT SIDE: ");
    for (int i = mid + 1; i <= high; i++) printf("\t%d", x[i]);
    printf("\nSIZE OF TEMP ARRAY: %d", len);
    */

    int lPtr = low;
    int rPtr = mid+1;

    int temp[len];
    
    for (int i = 0; i < len; i++) {
        if (lPtr == mid + 1) temp[i] = x[rPtr++];
        else if (rPtr == high + 1) temp[i] = x[lPtr++];
        else if (x[lPtr] < x[rPtr]) temp[i] = x[lPtr++];
        else temp[i] = x[rPtr++];
    }

    /*
    printf("\nTEMP ARRAY: ");
    for (int i = 0; i < high-low+1; i++) printf("%d ", temp[i]);
    */

    int j = 0;
    for (int i = low; i <= high; i++) {
        x[i] = temp[j];
        j++;
    }
}
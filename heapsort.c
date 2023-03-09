#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>

//gcc heapsort.c -lm
//parts of this program are inspired by my old heapsort from CS163 in highschool 

int *x;
int n;

void heapify(int i, int N);
void heapSort();
void visualHeap();

int main (void) {
    printf("How many values would you like? ");
    scanf("%d", &n);
    x = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter a value: ");
        scanf("%d", &x[i]);
    }

    int startIdx = (n/2) - 1;
    for (int i = startIdx; i >= 0; i--) heapify(i, n);

    printf("\nHeap array: ");
    for (int i = 0; i < n; i++)  printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");

    printf("\nVisual representation of heap:\n");
    visualHeap();

    heapSort();

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)  printf("%d%s", x[i], (i == n - 1) ? "\n" : " ");
    free(x);
    return EXIT_SUCCESS;
}

void heapify(int i, int N) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && x[l] > x[largest]) largest = l;
    if (r < N && x[r] > x[largest]) largest = r;
    
    if (largest != i) {
        int temp = x[i];
        x[i] = x[largest];
        x[largest] = temp;
        heapify(largest, N);
    }
}

void heapSort() {
    for (int i = n - 1; i >= 0; i--) {
        int temp = x[0];
        x[0] = x[i];
        x[i] = temp;

        heapify(0, i);
    }
}

void visualHeap() {
    int *temp = (int*) malloc(sizeof(int) * (n + 1));
    for (int i = 1; i < n + 1; i++) temp[i] = x[i - 1];
    int levels = ceil(log2(n));
    int idx = 1;
    for(int i = 0; i < levels; i++) {
        int num = idx;
        for (int j = 0; j < num; j++) {
            if (idx <= n) {
                printf("%d ", temp[idx]);
                idx++;
            }
        }
        printf("\n");
        if (i < levels - 1) {
            for (int k = 0; k < pow(2, i); k++) printf("/\\ ");
            printf("\n");
        }
    }
    free(temp);
}
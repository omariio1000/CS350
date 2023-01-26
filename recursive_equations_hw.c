#include <stdio.h>
#include <stdlib.h>

//cc recursive_equations_hw.c

#ifndef MAX
    #define MAX 10
#endif    

void q1(int prev1, int prev2, int count);
void q2(int prev, int count);
void q3(int prev1, int prev2, int count);
void q4(int prev, int count);
void q5(int prev, int count);

int main(void) {
    int question;
    printf("Which question would you like to see the recursive results for: ");
    scanf("%d", &question);
    if (question < 1) printf("Can't be lower than 1.");
    else if (question > 7) printf("Only 7 problems.");

    if (question == 1) {
        printf("f(1) = 1\nf(2) = 2\n");
        q1(2, 1, 3);
    }
    else if (question == 2) {
        printf("f(1) = 2\n");
        q2(2, 2);
    }
    else if (question == 3) {
        printf("f(1) = 1\nf(2) = 3\n");
        q3(3, 1, 3);
    }
    else if (question == 4) {
        printf("f(1) = 1\n");
        q4(1, 2);
    }
    else if (question == 5) {
        printf("f(0) = 1\n");
        q5(1, 1);
    }
    else if (question == 6) {
        printf("f(1) = 2\nf(2) = 3\n");
        q1(3, 2, 3);
    }
    else if (question == 7) {
        printf("f(1) = 1\n");
        q2(1, 2);
    }
}

void q1(int prev1, int prev2, int count) {
    if (count > MAX) return;
    int temp = prev1 + prev2;
    printf("f(%d) = %d\n", count, temp);
    return q1(temp, prev1, count + 1);
}

void q2(int prev, int count) {
    if (count > MAX) return;
    int temp = 3 * prev - 1;
    printf("f(%d) = %d\n", count, temp);
    return q2(temp, count + 1);
}

void q3(int prev1, int prev2, int count) {
    if (count > MAX) return;
    int temp = (2 * prev2) + prev1;
    printf("f(%d) = %d\n", count, temp);
    return q3(temp, prev1, count + 1);
}

void q4(int prev, int count) {
    if (count > MAX) return;
    int temp = prev * (2 * count - 1);
    printf("f(%d) = %d\n", count, temp);
    return q4(temp, count + 1);
}

void q5(int prev, int count) {
    if (count > MAX) return;
    int temp = prev + count;
    printf("f(%d) = %d\n", count, temp);
    return q5(temp, count + 1);
}
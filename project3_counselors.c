// project3_counselors.c - Find the counselor that has not been assigned
// Dang Bao Trinh

#include <stdio.h>

/*
   Function: search
   Purpose: Find the counselor number that has not been assigned.
   counselors[] contains n-1 assigned counselor numbers (from 1 to n).
   n is the total number of counselors.
*/
int search(int counselors[], int n) {
    int total = n * (n + 1) / 2;  // Sum of numbers from 1 to n
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        sum += counselors[i];
    }

    return total - sum;  // Missing counselor
}

int main(void) {
    int n;

    printf("Enter number of counselors: ");
    if (scanf("%d", &n) != 1)
        return 0;

    int counselors[n - 1];

    printf("Enter counselors assigned: ");
    for (int i = 0; i < n - 1; i++) {
        if (scanf("%d", &counselors[i]) != 1)
            return 0;
    }

    int missing = search(counselors, n);

    printf("Counselor has not been assigned: %d\n", missing);

    return 0;
}

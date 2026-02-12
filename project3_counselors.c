cat > project3_counselors.c <<'EOF'
// project3_counselors.c - Find the counselor that has not been assigned
// Dang Bao Trinh

#include <stdio.h>

/* Search function:
   counselors[] contains n-1 assigned counselor numbers (each 1..n).
   Return the counselor number in 1..n that is missing.
*/
int search(int counselors[], int n) {
    int total = n * (n + 1) / 2;  // sum 1..n
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += counselors[i];
    }
    return total - sum;
}

int main(void) {
    int n;

    /* Prompt exactly as required */
    printf("Enter number of counselors: ");
    if (scanf("%d", &n) != 1) return 0;

    /* allocate array to hold n-1 assigned counselors */
    int counselors[n - 1];

    printf("Enter counselors assigned: ");
    for (int i = 0; i < n - 1; i++) {
        if (scanf("%d", &counselors[i]) != 1) return 0;
    }

    int missing = search(counselors, n);

    printf("Counselor has not been assigned: %d\n", missing);

    return 0;
}
EOF

// Project 3 - AC Rental Program using Arrays 
// Dang Bao Trinh

#include <stdio.h>

int main(void) {
    int selection, days;

    // Three arrays storing pricing information for 4 AC types
    // Index 0 -> Type 1, Index 1 -> Type 2, etc.
    int firstDay[4]   = {50, 60, 80, 200};   // First day rental cost
    int afterFirst[4] = {30, 35, 50, 120};   // Daily rate after first day
    int perWeek[4]    = {160, 200, 280, 550}; // Weekly maximum charge

    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection:");
    
    // Read AC selection
    if (scanf("%d", &selection) != 1)
        return 0;

    // Validate selection range
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    printf("Enter days:");
    
    // Read number of rental days
    if (scanf("%d", &days) != 1)
        return 0;

    // Validate days (must be >= 0)
    if (days < 0) {
        printf("Invalid days.\n");
        return 0;
    }

    // Convert user selection (1-4) to array index (0-3)
    int idx = selection - 1;
    int charge = 0;

    // Case 1: No rental
    if (days == 0) {
        charge = 0;
    }
    // Case 2: Rental within 7 days
    else if (days <= 7) {
        // Calculate cost: first day + remaining days
        charge = firstDay[idx] + (days - 1) * afterFirst[idx];

        // Apply weekly maximum cap if exceeded
        if (charge > perWeek[idx])
            charge = perWeek[idx];
    }
    // Case 3: Rental more than 7 days
    else {
        // First 7 days capped at weekly maximum
        charge = perWeek[idx];

        // Remaining days after first week
        int remaining = days - 7;

        // Full additional weeks
        int weeks = remaining / 7;

        // Remaining extra days after full weeks
        int rem = remaining % 7;

        // Add full weeks (each capped at weekly maximum)
        charge += weeks * perWeek[idx];

        // Calculate remaining days using daily rate (no first-day charge anymore)
        int remCharge = rem * afterFirst[idx];

        // Apply weekly cap if remaining part exceeds weekly max
        if (remCharge > perWeek[idx])
            remCharge = perWeek[idx];

        charge += remCharge;
    }

    // Display final charge
    printf("Charge($): %d\n", charge);

    return 0;
}

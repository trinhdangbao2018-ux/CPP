#include <stdio.h>

int main(void) {
    int selection, days;
    int first_day = 0, daily_rate = 0, week_max = 0;
    int charge = 0;

    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection:");
    if (scanf("%d", &selection) != 1) {
        return 0;
    }

    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    printf("Enter days:");
    if (scanf("%d", &days) != 1) {
        return 0;
    }

    if (days < 0) {
        printf("Invalid days.\n");
        return 0;
    }

    switch (selection) {
        case 1:
            first_day = 50;  daily_rate = 30;  week_max = 160;
            break;
        case 2:
            first_day = 60;  daily_rate = 35;  week_max = 200;
            break;
        case 3:
            first_day = 80;  daily_rate = 50;  week_max = 280;
            break;
        case 4:
            first_day = 200; daily_rate = 120; week_max = 550;
            break;
        default:
            return 0;
    }

    if (days == 0) {
        charge = 0;
    } else if (days <= 7) {

        charge = first_day + (days - 1) * daily_rate;
        if (charge > week_max) charge = week_max;
    } else {

        int weeks = days / 7;
        int rem = days % 7;

        int week_charge = 7 * daily_rate;
        if (week_charge > week_max) week_charge = week_max;

        charge = weeks * week_charge;

        int rem_charge = rem * daily_rate;
        if (rem_charge > week_max) rem_charge = week_max;

        charge += rem_charge;
    }

    printf("Charge($): %d\n", charge);
    return 0;
}

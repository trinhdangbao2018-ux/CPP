// Bao Dang Trinh
// ASCII Stream Analyzer Program

#include <stdio.h>

int main(void)
{
    char ch;        // stores one character read from input
    int ascii;      // stores ASCII value of the character

    // Outer loop keeps program running until # is entered
    do
    {
        // Prompt shown at the start and after each ENTER
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):\n");

        // Inner loop processes each character typed before ENTER
        while (1)
        {
            ch = getchar();   // read one character from input

            // If user presses ENTER, stop processing this line
            if (ch == '\n')
            {
                break;
            }

            // If user types #, terminate the program
            if (ch == '#')
            {
                return 0;
            }

            // Get ASCII value of the character
            ascii = ch;

            //print the character and its ASCII code
            printf("\nYou typed: '%c' (ASCII %d)\n", ch, ascii);

            // Check if character is an uppercase letter
            if (ascii >= 65 && ascii <= 90)
            {
                printf("Class: Uppercase Letter\n");
                ch = ch + 32;   // convert to lowercase
                printf("Converted to: '%c'\n", ch);
            }
            // Check if character is a lowercase letter
            else if (ascii >= 97 && ascii <= 122)
            {
                printf("Class: Lowercase Letter\n");
                ch = ch - 32;   // convert to uppercase
                printf("Converted to: '%c'\n", ch);
            }
            // Check if character is a digit
            else if (ascii >= 48 && ascii <= 57)
            {
                printf("Class: Digit\n");
                printf("Converted to: '%c'\n", ch);
            }
            // Check if character is a printable symbol
            else if (ascii >= 32 && ascii <= 126)
            {
                printf("Class: Printable Symbol\n");
                printf("Converted to: '%c'\n", ch);
            }
            //Otherwise, character is non-printable
            else
            {
                printf("Class: Non-printable Character\n");
                printf("Converted to: '%c'\n", ch);
            }
        }

    } while (1);   //loop continues until '#' is entered

    return 0;
}

// Bao Dang Trinh
// ASCII Stream Analyzer Program


#include <stdio.h>

int main(void)
{
    int c;          
    char ch;        
    int ascii;     

    // This outer loop keeps the program running
    // It will only stop when the user enters '#'
    do
    {
        //Display the prompt at the beginning and after each ENTER
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):\n");

        //This inner loop processes each character typed before ENTER
        while (1)
        {
            // Read one character from input
            c = getchar();

            //If the user presses ENTER, stop processing this line
            //And return to the outer loop so the prompt prints again
            if (c == '\n')
            {
                printf("\n");   // print a blank line before the next prompt
                break;
            }

            //If the user types '#', terminate the program immediately
            if (c == '#')
            {
                return 0;
            }

            //Convert the input value to a character
            ch = (char)c;

            //Store the ASCII value of the character
            ascii = (unsigned char)ch;

            //Print the character and its ASCII code
            printf("\nYou typed: '%c' (ASCII %d)\n", ch, ascii);

            //Check if the character is an uppercase letter (A–Z)
            if (ascii >= 65 && ascii <= 90)
            {
                printf("Class: Uppercase Letter\n");
                //Convert uppercase to lowercase by adding 32
                ch = ch + 32;
                printf("Converted to: '%c'\n", ch);
            }
            //Check if the character is a lowercase letter (a–z)
            else if (ascii >= 97 && ascii <= 122)
            {
                printf("Class: Lowercase Letter\n");
                //Convert lowercase to uppercase by subtracting 32
                ch = ch - 32;
                printf("Converted to: '%c'\n", ch);
            }
            //Check if the character is a digit (0–9)
            else if (ascii >= 48 && ascii <= 57)
            {
                printf("Class: Digit\n");
                //Digits are not converted
                printf("No conversion done\n");
            }
            //Check if the character is a printable symbol
            else if (ascii >= 32 && ascii <= 126)
            {
                printf("Class: Printable Symbol\n");
                //Symbols are not converted
                printf("No conversion done\n");
            }
            //All other characters are non-printable or extended ASCII
            else
            {
                printf("Class: Non-printable or extended ASCII\n");
                //Non-printable characters are not converted
                printf("No conversion done\n");
            }
        }

    } while (1);   //loop continues until '#' is entered

    return 0;
}

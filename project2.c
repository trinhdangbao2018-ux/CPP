// Bao Dang Trinh

#include <stdio.h>

int main(void)
{
    int c;          // use int for getchar() (recommended)
    char ch;
    int ascii;

    do
    {
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):\n");

        while (1)
        {
            c = getchar();

            if (c == '\n')
            {
                printf("\n");     // blank line before the next prompt (matches expected)
                break;
            }

            if (c == '#')
            {
                return 0;
            }

            ch = (char)c;
            ascii = (unsigned char)ch;

            printf("\nYou typed: '%c' (ASCII %d)\n", ch, ascii);

            if (ascii >= 65 && ascii <= 90)
            {
                printf("Class: Uppercase Letter\n");
                ch = ch + 32;
                printf("Converted to: '%c'\n", ch);
            }
            else if (ascii >= 97 && ascii <= 122)
            {
                printf("Class: Lowercase Letter\n");
                ch = ch - 32;
                printf("Converted to: '%c'\n", ch);
            }
            else if (ascii >= 48 && ascii <= 57)
            {
                printf("Class: Digit\n");
                printf("No conversion done\n");
            }
            else if (ascii >= 32 && ascii <= 126)
            {
                printf("Class: Printable Symbol\n");
                printf("No conversion done\n");
            }
            else
            {
                printf("Class: Non-printable or extended ASCII\n");
                printf("No conversion done\n");
            }
        }

    } while (1);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[100], str2[100];
    char copy[100], result[200], upper[100];
    int choice, i, len;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    do
    {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Find length of string\n");
        printf("2. Copy string\n");
        printf("3. Concatenate strings\n");
        printf("4. Compare strings\n");
        printf("5. Reverse string\n");
        printf("6. Convert to uppercase\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Length of string: %lu\n",
                       (unsigned long)strlen(str1));
                break;

            case 2:
                strcpy(copy, str1);
                printf("Copied string: %s\n", copy);
                break;

            case 3:
                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated string: %s\n", result);
                break;

            case 4:
                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;

            case 5:
                len = strlen(str1);

                printf("Reversed string: ");
                for (i = len - 1; i >= 0; i--)
                    printf("%c", str1[i]);

                printf("\n");
                break;

            case 6:
                strcpy(upper, str1);

                for (i = 0; upper[i] != '\0'; i++)
                    upper[i] = toupper((unsigned char)upper[i]);

                printf("Uppercase string: %s\n", upper);
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}

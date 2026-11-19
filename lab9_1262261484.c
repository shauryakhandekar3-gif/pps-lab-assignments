#include <stdio.h>

int main()
{
    FILE *source, *destination;
    char ch;
    char file1[100], file2[100];

    printf("Enter source file name: ");
    scanf("%99s", file1);

    printf("Enter destination file name: ");
    scanf("%99s", file2);

    source = fopen(file1, "r");

    if (source == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    destination = fopen(file2, "w");

    if (destination == NULL)
    {
        printf("Unable to create destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
/**
 * factorize - function that make the facters of N input
 * @number: the input number
 */
void factorize(int number)
{
        int i;

        for (i = 2; i <= number / 2; i++)
                if (number % i == 0)
                        printf("%d=%d*%d\n", number, i, number / i);
}
/**
 * file_opener - function to deal with the needed file
 * @file_path: the file directory track
 */
void file_opener(const char *file_path)
{
        FILE *file = fopen(file_path, "r");

        if (file == NULL)
        {
                printf("Failed to open the file.\n");
                return;
        }

        int n;

        while (fscanf(file, "%d", &n) == 1)
                factorize(n);
        fclose(file);
}
/**
 * main - the main entrance of the functions
 * @argc: numbeer if arguments
 * @argv: the list of args
 * Return: 0 as the success
 */
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                printf("Usage: ./factors <file>\n");
                return (1);
        }

        const char *file_path = argv[1];

        file_opener(file_path);
        return (0);
}

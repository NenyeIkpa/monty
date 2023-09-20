#include "monty.h"

#define SIZE 60

/**
 * remove_white_spaces - removes white spaces in a string
 *
 * @str: provided string
 *
 * Return: string
 */

char *remove_white_spaces(char *str)
{
	int i, j = 0;

	for (i = 0; (size_t)i < strlen(str); i++)
	{
		if (str[i] != ' ' || (i > 0  && str[i-1] != ' '))
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}	

/**
 * main - entry point to interpreter for monty bytecode files
 *
 * @argc: total number of arguments passed to main
 * @argv: list of arguments passed to main
 *
 * Return: int
 */

int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *filename, buffer[SIZE];

	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file_ptr = fopen(filename, "r");
	if (file_ptr == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, SIZE, file_ptr) != NULL)
	{
		fputs(buffer, stdout);
		fputs(remove_white_spaces(buffer), stdout);
	}
	fclose(file_ptr);
	return (0);
}

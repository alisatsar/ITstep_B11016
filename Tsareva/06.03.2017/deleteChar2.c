//Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.

#include <stdio.h>

#define SIZE_STRING 500

int findLength(char* str);
void deleteChar(char* str, int* len);

int main()
{
	char str[SIZE_STRING];

	printf("Enter your text:\n");
	fgets(str, SIZE_STRING, stdin);

	int len = findLength(str);
	
	deleteChar(str, &len);
}

int findLength(char* str)
{
	int count = 0;

	do{
		count++;
	} while (*(str + count) != 0);

	return count - 1;
}

void deleteChar(char* str, int* len)
{
	char deleteChar;
	printf("Enter character, what you want delete:\n");
	scanf("%c", &deleteChar);

	for (int i = 0; i < *len; i++)
	{
		if (*(str + 0) == deleteChar)
		{
			i = 0;
		}
		if (*(str + i) == deleteChar)
		{
			for (int j = i; j < *len; j++)
			{
				*(str + j) = str[j + 1];
				if ((*(str + j) == '\n'))
				{
					*(str + j) = '\0';
				}
			}
			if ((*(str + i) == deleteChar))
			{
				i--;
			}
		}
	}
	puts(str);
}
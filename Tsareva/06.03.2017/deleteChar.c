//Написать функцию, которая удаляет из строки символ с заданным номером

#include <stdio.h>

#define SIZE_STRING 500

int length(char* str);
void deliteChar(char* str, int* len);

int main()
{
	char str[SIZE_STRING];

	printf("Enter your text:\n");
	fgets(str, SIZE_STRING, stdin);

	int len = length(str);

	deliteChar(str, &len);
}

int length(char* str)
{
	int count = 0;

	do {
		count++;
	} while (str[count] != 0);

	return count - 1;
}

void deliteChar(char* str, int* len)
{
	int userDeleteChar;

	printf("The text contains %i character. Enter the number of character, that you want delete:\n", *len);
	scanf("%i", &userDeleteChar);
	
	while (userDeleteChar > *len)
	{
		printf("The text contains %i character. You are enter the number of character, that not exist.\nPlease, try again:\n", *len);
		scanf("%i", &userDeleteChar);
	}

	for (int i = userDeleteChar - 1; i < *len; i++)
	{
		if (userDeleteChar > 0)
		{
			str[i] = str[i + 1];
		}
	}
	puts(str);
}
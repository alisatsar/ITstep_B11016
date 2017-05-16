/*Задание 1
Написать функцию, которая вставляет в строку в указанную позицию заданный символ.*/

#include <stdio.h>

#define SIZE_STRING 500

int findLength(char* str);
void pasteCharacter(char* str, char* str2, int* len);

int main()
{
	char str[SIZE_STRING];
	char str2[SIZE_STRING];
	
	printf("Enter your text:\n");
	fgets(str, SIZE_STRING, stdin);

	int len = findLength(str);

	pasteCharacter(str, str2, &len);
}

int findLength(char* str)
{
	int count = 0;

	do {
		count++;
	} while (*(str + count) != 0);

	return count - 1;
}

void pasteCharacter(char* str, char* str2, int* len)
{
	char pasteChar;
	printf("Enter character, what you want paste:\n");
	scanf("%c", &pasteChar);

	int position;
	printf("Please, enter number of character, that you want to paste: ");
	scanf("%i", &position);

	while (position > *len)
	{
		printf("Your string contains %i character, please enter number of character: ", *len);
		scanf("%i", &position);
	}

	for (int i = 0; i < *len + 2; i++)
	{
		if (i < position - 1)
		{
			str2[i] = str[i];
		}
		else if (i == position - 1)
		{
			str2[i] = pasteChar;
		}
		else if (i > position - 1 && i < *len + 1)
		{
			str2[i] = str[i - 1];
		}
		else if(i == *len + 1)
		{
			str2[i] = 0;
		}
	}
	puts(str2);
}

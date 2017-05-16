/*Написать функцию, которая определяет, является ли введенное слово анаграммой*/

#include <stdio.h>

int findLength(char* str1);
void flipString(char* str1, char* str2, int length);
void compareStrings(char* str1, char* str2, int length);

int main()
{
	char str1[20];
	char str2[20];

	printf("Enter the word: ");
	fgets(str1, 20, stdin);

	int length = findLength(str1);

	flipString(str1, str2, length);
	
	puts(str2);

	compareStrings(str1, str2, length);
}

int findLength(char* str1)
{
	int count = 0;
	while (*str1 != '\n')
	{
		str1++;
		count++;
	}
	return count;
}

void flipString(char* str1, char* str2, int length)
{
	int j = length;
	for (int i = 0; i <= length/2 + 1; i++)
	{
		if (i == length/2)
		{
			str2[i] = 0;
		}
		else
		{
			str2[i] = str1[j - 1];
		}
		j--;
	}
}

void compareStrings(char* str1, char* str2, int length)
{
	int countCoincidence = 0;
	while (*str2 != 0)
	{
		if (*str1 == *str2)
		{
			countCoincidence++;
		}
		else
		{
			break;
		}
		str1++;
		str2++;
	}
	str1 = str1 - countCoincidence;
	if (countCoincidence == length/2)
	{
		printf("Word: %s is the anagram\n", str1);
	}
	else
	{
		printf("Word: %s is the not anagram\n", str1);
	}
}

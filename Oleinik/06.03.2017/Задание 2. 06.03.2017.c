//Задание 2:
//Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_ARRAY_ROW 1024

void printString(char* stringSymbols);
int deleteSymbol(char* stringSymbols);

int main()
{
	printf("Program for deleting symbols.\nEnter your sentence: ");
	char stringSymbols[STRING_ARRAY_ROW];
	fgets(stringSymbols, STRING_ARRAY_ROW, stdin);
	deleteSymbol(stringSymbols);
	printString(stringSymbols);
}

int deleteSymbol(char* stringSymbols)
{
	printf("Entre a symbol, that you want to delete: ");
	char symbolForDelete;
	scanf("%c", &symbolForDelete);
	int count = 0;
	for (int i = 0; i < STRING_ARRAY_ROW; i++)
	{
		if (symbolForDelete == stringSymbols[i])
		{

			stringSymbols[i] = ' ';
			count++;
		}
	}
	if (count == 0)
	{
		printf("I can't find this symbol. Please, enter another letter.\n");
		exit(0);
	}

}

void printString(char* stringSymbols)
{
	printf("%s", stringSymbols);
}

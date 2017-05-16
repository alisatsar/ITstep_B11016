//Задание 1:
//Написать функцию, которая удаляет из строки символ с заданным номером.

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define ARRAY_ROW 1024

int calcArrayLength(char* stringArray);
int choosingSymbol(char* stringArray);
void printstringWithDeletedSymbol(char* stringArray);

int main()
{
	printf("This programm can delete any symbol in string row.\nEnter your sentence: ");
	char stringArray[ARRAY_ROW];
	fgets(stringArray, ARRAY_ROW, stdin);
	int userNumberChoise = choosingSymbol(stringArray);
	printstringWithDeletedSymbol(stringArray);

}

int calcArrayLength(char* stringArray)
{
	int arrayLength = 0;
	while (*stringArray++ != 0)
	{
		arrayLength++;
	}
	return arrayLength - 1;
}

int choosingSymbol(char* stringArray)
{
	int arrayLength = calcArrayLength(stringArray);

	printf("Your array length contains %i symbols.\nNow, you can pick a number between 0 and %i to delete any letter in your sentence: ", arrayLength, arrayLength);
	int userNumberChoise;
	scanf("%i", &userNumberChoise);
	if (userNumberChoise > arrayLength || userNumberChoise < 0)
	{
		printf("Error! Make another choise.\n");
		choosingSymbol(stringArray);
	}
	stringArray[userNumberChoise] = ' ';
	return userNumberChoise;
}

void printstringWithDeletedSymbol(char* stringArray)
{
	printf("Your reformed sentence: ");
	printf("%s", stringArray);
}
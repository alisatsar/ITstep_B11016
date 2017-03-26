//Задание 1:
//Напишите программу поиска факториала числа без использования возвращения значения из функции факториала(return result;), 
//используйте указатель на переменную с результатом и передавайте ее в рекурсивную функцию(например, factor(int* result)).

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int factor(int userNumber, int* userNumberFactorial);

int main()
{
	setlocale(LC_ALL, "rus");
	printf("Программа высчитает факториал введённого числа с клавиатуры.\nВведите число: ");
	int userNumber;
	scanf("%i", &userNumber);
	int userNumberFactorial = 1;
	factor(userNumber, &userNumberFactorial);
	printf("Факториал числа равен: %i\n", userNumberFactorial);
}

int factor(int userNumber, int* userNumberFactorial)
{
	if (userNumber > 1)
	{
		factor(userNumber - 1, userNumberFactorial);
		*userNumberFactorial *= userNumber;
	}
}


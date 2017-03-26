//Задание 2:
//Напишите программу возведения чисел в степень, используйте указатели для передачи результирующего значения в функцию и из нее.
//Числа необходимо получать от пользователя.

#include <stdio.h>
#include <locale.h>

void getDegreeForUserNumber(int*userNumber, int* degreesNumber, int* answerForUser);

int main()
{
	setlocale(LC_ALL, "Rus");
	int userNumber;
	printf("Программа высчитывает степень числа введенные с клавиатуры.\nВведите желаемое число: ");
	scanf("%i", &userNumber);
	int degreesNumber;
	printf("Введите степень для числа: ");
	scanf("%i", &degreesNumber);
	int answerForUser = 1;
	getDegreeForUserNumber(&userNumber, &degreesNumber, &answerForUser);
	printf("%i\n", answerForUser);
}

void getDegreeForUserNumber(int* userNumber, int* degreesNumber, int* answerForUser)
{
	for (int i = 0; i < *degreesNumber; i++)
	{
		*answerForUser *= *userNumber;
	}
}
//Напишите программу, которая создает двухмерный массив и заполняет его по
//следующему принципу : пользователь вводит число(например, 3) первый элемент массива
//принимает значение этого числа, последующий элемент массива принимает значение
//этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива
//предыдущий элемент умноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный
//массив вывести на экран.


#include <stdio.h>
#include <locale.h>

int getNumbersForMassiv(int massiv[2][5], int massivsLines, int massivsColumn);
void printMassiv(int massiv[2][5], int massivsLines, int massivsColumn);

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Добрый вечер. Вам предлагается заполнить массив буквально в два клика.\n"
		"Введите целое число (например: 2), и последующее число будет умножаться на два от предыдущего значения.\nВаше число: ");
	int massiv[2][5];
	getNumbersForMassiv(massiv, 2, 5);
	printMassiv(massiv, 2, 5);
}

int getNumbersForMassiv(int massiv[2][5], int massivsLines, int massivsColumn)
{
	scanf("%i", &massiv[0][0]);
	for (int j = 1; j < massivsColumn; j++)
	{
		massiv[0][j] = massiv[0][j - 1] * 2;
	}
	massiv[1][0] = massiv[0][4] * 2;
	for (int i = 1; i < massivsColumn; i++)
	{
		massiv[1][i] = massiv[1][i - 1] * 2;
	}
	return massiv;
}

void printMassiv(int massiv[2][5], int massivsLines, int massivsColumn)
{
	for (int k = 0; k < massivsLines; k++)
	{
		for (int l = 0; l < massivsColumn; l++)
		{
			printf("massiv [%i][%i]: %i\n", k, l, massiv[k][l]);
		}
	}
}
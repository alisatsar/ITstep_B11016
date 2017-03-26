/* Задание 1: Напишите программу, которая создает двухмерный массив и заполняет его по
   следующему принципу : пользователь вводит число(например, 3) первый элемент массива
   принимает значение этого числа, последующий элемент массива принимает значение
   этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива
   предыдущий элемент умноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный
   массив вывести на экран. */

#include <stdio.h>

#define ROW 4
#define COLUMN 4

void fillMatrix(int matrix[][COLUMN], int row, int column);
void printMatrix(int matrix[][COLUMN], int row, int column);

int main()
{
	int matrix[ROW][COLUMN];
	printf("Davajte zapolnim matricu!\nVvedite chislo(ot -6 do 20): ");
	int userNumber;
	scanf("%i", &userNumber);
	while (userNumber > 20 || userNumber < -6)
	{
		printf(userNumber > 20 ? "Slishkom bol'shoe chislo.\n" : "Slishkom malen'koje chislo.\n");
		scanf("%i", &userNumber);
	}
	matrix[0][0] = userNumber;
	fillMatrix(matrix, ROW, COLUMN);
	printf("Vot chto poluchilos'!\n");
	printMatrix(matrix, ROW, COLUMN);
	return 0;
}

void fillMatrix(int matrix[][COLUMN], int row, int column)
{
	int buffer = matrix[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = buffer;
			buffer = matrix[i][j] * 2;
		}
	}
}

void printMatrix(int matrix[][COLUMN], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf(" %i\t\t", matrix[i][j]);
		}
		printf("\n\n");
	}
}
//Задание 1
//Написать функцию, которая получает указатель на статический двумерный массив(3x5) и
//его размер.Функция распределяет положительные, отрицательные и нулевые элементы в
//3 отдельных массива, указатели на которые также переданы в функцию.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define ARRAY_ROW 3
#define ARRAY_COLUMN 5

void fillMainArray(int(*pArray)[ARRAY_COLUMN], int arrayRow, int arrayColumn);
void transferNumbersFromMainArrayToAuxiliaryArray(int(*pArray)[ARRAY_COLUMN], int arrayRow, int arrayColumn, int(*pArrayForNegNumbers)[ARRAY_COLUMN], int(*pArrayForPosNumbers)[ARRAY_COLUMN], int(*pArrayForZero)[ARRAY_COLUMN]);
enum ChooseBetweenPosNegZero
{
	PosNumbers = 1,
	NegNumbers,
	ZeroNumbers
};

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int array[ARRAY_ROW][ARRAY_COLUMN];
	int arrayForNegNumbers[ARRAY_ROW][ARRAY_COLUMN];
	int arrayForPosNumbers[ARRAY_ROW][ARRAY_COLUMN];
	int arrayForZero[ARRAY_ROW][ARRAY_COLUMN];
	fillMainArray(array, ARRAY_ROW, ARRAY_COLUMN);
	transferNumbersFromMainArrayToAuxiliaryArray(array, ARRAY_ROW, ARRAY_COLUMN, arrayForNegNumbers, arrayForPosNumbers, arrayForZero);

}

void fillMainArray(int(*pArray)[ARRAY_COLUMN], int arrayRow, int arrayColumn)
{
	printf("Ваша матрица имеет следующий вид:\n");
	for (int i = 0; i < arrayRow; i++)
	{
		for (int j = 0; j < arrayColumn; j++)
		{
			*(*(pArray + i) + j) = -5 + rand() % 10;
			printf("%i ", *(*(pArray + i) + j));
		}
		printf("\n");
	}
}

void transferNumbersFromMainArrayToAuxiliaryArray(int(*pArray)[ARRAY_COLUMN], int arrayRow, int arrayColumn, int(*pArrayForNegNumbers)[ARRAY_COLUMN], int(*pArrayForPosNumbers)[ARRAY_COLUMN], int(*pArrayForZero)[ARRAY_COLUMN])
{
	int countForPosNumbers = 0;
	int countForNegNumbers = 0;
	int countForZero = 0;

	int posRow = 0;
	int posColumn = 0;
	int negRow = 0;
	int negColumn = 0;
	int zeroRow = 0;
	int zeroColumn = 0;

	for (int k = 0; k < arrayRow; k++)
	{
		for (int l = 0; l < arrayColumn; l++)
		{
			if (*(*(pArray + k) + l) > 0)
			{
				*(*(pArrayForPosNumbers + posRow) + posColumn) = *(*(pArray + k) + l);
				countForPosNumbers++;
				posColumn++;
				if (posColumn == 5)
				{
					posRow++;
					posColumn = 0;
				}
			}
		}
	}
	for (int m = 0; m < arrayRow; m++)
	{
		for (int n = 0; n < arrayColumn; n++)
		{
			if (*(*(pArray + m) + n) < 0)
			{
				*(*(pArrayForNegNumbers + negRow) + negColumn) = *(*(pArray + m) + n);
				countForNegNumbers++;
				negColumn++;
				if (negColumn == 5)
				{
					negRow++;
					negColumn = 0;
				}
			}
		}
	}
	for (int o = 0; o < arrayRow; o++)
	{
		for (int p = 0; p < arrayColumn; p++)
		{
			if (*(*(pArray + o) + p) == 0)
			{
				*(*(pArrayForZero + zeroRow) + zeroColumn) = *(*(pArray + o) + p);
				countForZero++;
				zeroColumn++;
				if (zeroColumn == 5)
				{
					zeroRow++;
					zeroColumn = 0;
				}
			}
		}
	}

	enum ChooseBetweenPosNegZero chooseBetweenPosNegZero;
	printf("Какую функцию выполним:\n1. Вывод матрицы положительных чисел.\n2. Вывод матрицы отрицательных чисел.\n3. Вывод матрицы нулей.\n");
	scanf("%i", &chooseBetweenPosNegZero);
	switch (chooseBetweenPosNegZero)
	{
	case PosNumbers:
		printf("Матрица положительных чисел будет иметь следующий вид:\n");
		for (int m = 0; m < arrayRow; m++)
		{
			for (int n = 0; n < arrayColumn; n++)
			{
				countForPosNumbers--;
				if (countForPosNumbers < 0)
				{
					break;
				}
				printf("%i ", *(*(pArrayForPosNumbers + m) + n));
			}
			printf("\n");
			if (countForPosNumbers < 0)
			{
				break;
			}
			
		}
		break;
	case NegNumbers:
		printf("Матрица отрицательных чисел будет иметь следующий вид:\n");
		for (int m = 0; m < arrayRow; m++)
		{
			for (int n = 0; n < arrayColumn; n++)
			{
				countForNegNumbers--;
				if (countForNegNumbers < 0)
				{
					break;
				}
				printf("%i ", *(*(pArrayForNegNumbers + m) + n));
			}
			printf("\n");
			if (countForNegNumbers < 0)
			{
				break;
			}
		}
		break;
	case ZeroNumbers:
		printf("Матрица нулей будет иметь следующий вид:\n");
		for (int m = 0; m < arrayRow; m++)
		{
			for (int n = 0; n < arrayColumn; n++)
			{
				
				if (countForZero <= 0)
				{
					break;
				}
				countForZero--;
				printf("%i ", *(*(pArrayForZero + m) + n));
				
			}
			printf("\n");
			if (countForZero <= 0)
			{
				break;
			}
		}
		break;
	default:
		printf("Ошибка! Повторите ввод.\n");
		break;
	}
}
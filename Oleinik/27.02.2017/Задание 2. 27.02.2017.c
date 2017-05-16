//Задание 2
//Написать программу, которая содержит функцию, принимающую в качестве аргумента,
//указатели на три массива и размер массивов.Функция заносит в массив C суммы
//элементов массивов А и В.Размер массивов одинаковый.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define ARRAY_ROW 5

void fillMainArray(int* auxiliaryArrayA, int* auxiliaryArrayB, int arrayRow);
void additionSumOfAuxiliaryArrays(int* auxiliaryArrayA, int* auxiliaryArrayB, int* mainArray, int arrayRow);
void printArrays(int* auxiliaryArrayA, int* auxiliaryArrayB, int* mainArray, int arrayRow);

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int mainArray[ARRAY_ROW];
	int auxiliaryArrayA[ARRAY_ROW];
	int auxiliaryArrayB[ARRAY_ROW];
	fillMainArray(auxiliaryArrayA, auxiliaryArrayB, ARRAY_ROW);
	additionSumOfAuxiliaryArrays(auxiliaryArrayA, auxiliaryArrayB, mainArray, ARRAY_ROW);
	printArrays(auxiliaryArrayA, auxiliaryArrayB, mainArray, ARRAY_ROW);
}

void fillMainArray(int* auxiliaryArrayA, int* auxiliaryArrayB, int arrayRow)
{
	for (int i = 0; i < arrayRow; i++)
	{
		*(auxiliaryArrayA + i) = rand() % 10;
		*(auxiliaryArrayB + i) = rand() % 10;
	}
}

void additionSumOfAuxiliaryArrays(int* auxiliaryArrayA, int* auxiliaryArrayB, int* mainArray, int arrayRow)
{
	for (int j = 0; j < arrayRow; j++)
	{
		*(mainArray + j) = *(auxiliaryArrayA + j) + *(auxiliaryArrayB + j);
	}
}

void printArrays(int* auxiliaryArrayA, int* auxiliaryArrayB, int* mainArray, int arrayRow)
{
	printf("Первый массив:\n");
	for (int k = 0; k < arrayRow; k++)
	{
		printf("%i ", *(auxiliaryArrayA + k));
	}
	printf("\nВторой массив:\n");
	for (int l = 0; l < arrayRow; l++)
	{
		printf("%i ", *(auxiliaryArrayB + l));
	}
	printf("\nСумма элементов массива:\n");
	for (int m = 0; m < arrayRow; m++)
	{
		printf("%i ", *(mainArray + m));
	}
}


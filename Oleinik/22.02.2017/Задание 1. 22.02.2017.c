//Задание 1:
//Используя два указателя на массив целых чисел, скопировать один массив в другой.
//Использовать в программе арифметику указателей для продвижения по массиву, а также
//оператор разыменования.

#include <stdio.h>
#include <locale.h>

void arrayCoping(int* pArray, int* pCopyArray, int arratRow);

#define ARRAY_ROW 5

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_ROW];
	printf("Программа выполнит копирование значений из одного массива в другой используя указатели.\nВведите массив: ");
	for (int i = 0; i < ARRAY_ROW; i++)
	{
		scanf("%i", &array[i]);
	}
	int copyArray[ARRAY_ROW];
	arrayCoping(&array, &copyArray, ARRAY_ROW);
	printf("Скопированный массив:\n");
	for (int i = 0; i < ARRAY_ROW; i++)
	{
		printf("%i ", copyArray[i]);
	}
}

void arrayCoping(int* pArray, int* pCopyArray, int arratRow)
{
	for (int j = 0; j < arratRow; j++)
	{
		*(pCopyArray + j) = *(pArray + j);
	}
}


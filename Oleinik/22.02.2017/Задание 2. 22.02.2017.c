//Задание 2:
//Используя указатель на массив целых чисел, изменить порядок следования элементов
//массива на противоположный.Использовать в программе арифметику указателей для
//продвижения по массиву, а также оператор разыменования.

#include <stdio.h>
#include <locale.h>

#define ARRAY_ROW 5

void changingOrderOfNumbers(int* pArray);

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_ROW];
	for (int i = 0; i < ARRAY_ROW; i++)
	{
		scanf("%i", &array[i]);
	}
	changingOrderOfNumbers(&array);
	for (int l = 0; l < ARRAY_ROW; l++)
	{
		printf("%i ", array[l]);
	}
}

void changingOrderOfNumbers(int* pArray)
{
	int arrayForChange[ARRAY_ROW];
	int count = ARRAY_ROW - 1;
	for (int j = 0; j < ARRAY_ROW; j++)
	{
		arrayForChange[j] = *(pArray + count);
		count--;
	}
	for (int k = 0; k < ARRAY_ROW; k++)
	{
		*(pArray + k) = arrayForChange[k];
	}
}

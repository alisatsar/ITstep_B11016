//Задание 1:
//В одномерном массиве, состоящем из N вещественных чисел вычислить :
//• Сумму отрицательных элементов
//• Произведение элементов, находящихся между min и max элементами
//• Произведение элементов с четными номерами
//• Сумму элементов, находящихся между первым и последним отрицательными
//элементами.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
 
#define KOLLICHESTVO_CIFR_V_MASSIVE 10

int funkciiaDlaSuumiOtricatelnihZnachenii(int massiv[]);
int funkciiaDlaProizvediniaElementovMezhdyMinIMax(int massiv[]);

int main()
{
	setlocale(LC_ALL ,"Rus");
	srand(time(0));
	int massiv[KOLLICHESTVO_CIFR_V_MASSIVE];
	for (int i = 0; i < KOLLICHESTVO_CIFR_V_MASSIVE; i++)
	{
		massiv[i] = -5 + rand() % 10;
		printf("%i ", massiv[i]);
	}
	
	printf("\nСумма всех отричательных чисел в комбинации: %i\n", funkciiaDlaSuumiOtricatelnihZnachenii(massiv));
	printf("Произведение чисел между минимальным и максимальным значениями: %i\n", funkciiaDlaProizvediniaElementovMezhdyMinIMax(massiv));
}

int funkciiaDlaSuumiOtricatelnihZnachenii(int massiv[])
{
	int peremennaDlaCymmiOtricatelnihChisel = 0;
	for (int j = 0; j < KOLLICHESTVO_CIFR_V_MASSIVE; j++)
	{
		if (massiv[j] < 0)
		{
			peremennaDlaCymmiOtricatelnihChisel = peremennaDlaCymmiOtricatelnihChisel + massiv[j];
		}
	}
	return peremennaDlaCymmiOtricatelnihChisel;
}

int funkciiaDlaProizvediniaElementovMezhdyMinIMax(int massiv[])
{
	int maxZnachenie = massiv[0];
	int minZnachenie = massiv[0];
	int chisloDlaOpredNomeraMassivaMax1;
	int chisloDlaOpredNomeraMassivaMin1;

	for (int k = 0; k < KOLLICHESTVO_CIFR_V_MASSIVE; k++)
	{
		if (massiv[k] >= maxZnachenie)
		{
			maxZnachenie = massiv[k];
			if (maxZnachenie == massiv[k])
			{
				chisloDlaOpredNomeraMassivaMax1 = k;
			}
		}
		if (massiv[k] <= minZnachenie)
		{
			minZnachenie = massiv[k];
			if (minZnachenie == massiv[k])
			{
				chisloDlaOpredNomeraMassivaMin1 = k;
			}
		}
	}
	printf("Максимальное число: %i\n", maxZnachenie);
	printf("Минимальное число: %i\n", minZnachenie);

	int chisloDlaOpredNomeraMassivaMax = chisloDlaOpredNomeraMassivaMax1;
	printf("Максимальный массив: %i\n", chisloDlaOpredNomeraMassivaMax);

	int chisloDlaOpredNomeraMassivaMin = chisloDlaOpredNomeraMassivaMin1;
	printf("Минимальный массив: %i\n", chisloDlaOpredNomeraMassivaMin);

	int ProizvediniaElementovMezhdyMinIMax = 1;
	if (chisloDlaOpredNomeraMassivaMax > chisloDlaOpredNomeraMassivaMin)
	{
		printf("Работа с максимума до минимума.\n");
		for (int i = chisloDlaOpredNomeraMassivaMin; i < chisloDlaOpredNomeraMassivaMax + 1; i++)
		{
			ProizvediniaElementovMezhdyMinIMax = (ProizvediniaElementovMezhdyMinIMax) * (massiv[i]);
		}
		return ProizvediniaElementovMezhdyMinIMax;
	}
	if (chisloDlaOpredNomeraMassivaMin > chisloDlaOpredNomeraMassivaMax)
	{
		printf("Работа с минимума до максимума.\n");
		for (int i = chisloDlaOpredNomeraMassivaMax; i < chisloDlaOpredNomeraMassivaMin + 1; i++)
		{
			ProizvediniaElementovMezhdyMinIMax = (ProizvediniaElementovMezhdyMinIMax) * massiv[i];
		}
		return ProizvediniaElementovMezhdyMinIMax;
	}
}
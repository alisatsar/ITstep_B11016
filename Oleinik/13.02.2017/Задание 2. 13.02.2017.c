//Задание 2: Есть стопка оладий различного радиуса.
//Единственная операция, проводимая с ними - между любыми двумя суем лопатку и меняем порядок оладий над лопаткой на обратный.
//Необходимо за минимальное количество операций таких отсортировать снизувверх по убыванию радиуса.

#include <stdio.h>
#include <locale.h>
#include <time.h>

#define MASS_SIZE 5

void printArray(int* puncakesDiametr[MASS_SIZE]);
void fillArray(int* puncakesDiametr[MASS_SIZE]);
void sortArray(int* puncakesDiametr[MASS_SIZE]);

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	printf("Вам дана стопка оладьев разного диаметра. Программа выполнит их сортировку от наименьшего к большему диметру.\n");
	
	int countChoise;
	int puncakesDiametr[MASS_SIZE];
	fillArray(puncakesDiametr);
	printArray(puncakesDiametr);
	sortArray(puncakesDiametr);
}

void printArray(int* puncakesDiametr[MASS_SIZE])
{
	for (int i = 0; i < MASS_SIZE; i++)
	{
		printf("%i ", puncakesDiametr[i]);
	}
	printf("\n");
}

void fillArray(int* puncakesDiametr[MASS_SIZE])
{
	for (int i = 0; i < MASS_SIZE; i++)
	{
		puncakesDiametr[i] = rand() % 10;
	}
}

void sortArray(int* puncakesDiametr[MASS_SIZE])
{
	int countBubble = 0;
	int chisloDlaZameni;
	for (int i = 0; i < MASS_SIZE - 1; i++)
	{
		for (int j = 0; j < MASS_SIZE - 1 - i; j++)
		{
			if (puncakesDiametr[j] > puncakesDiametr[j + 1])
			{
				printf("Переворот лопаткой.\n");
				printArray(puncakesDiametr);
				chisloDlaZameni = puncakesDiametr[j];
				puncakesDiametr[j] = puncakesDiametr[j + 1];
				puncakesDiametr[j + 1] = chisloDlaZameni;
				countBubble++;
			}
		}
	}
	printf("Итоговый результат: ");
	printArray(puncakesDiametr);
	printf("Колличество переворотов: %i\n", countBubble);
}
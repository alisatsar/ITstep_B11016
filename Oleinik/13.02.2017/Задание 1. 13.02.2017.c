//Задание 1: Написать программу «справочник».Создать два одномерных массива.Один
//массив хранит номера ICQ, второй – телефонные номера.Реализовать меню для
//пользователя :
//• Отсортировать по номерам ICQ
//• Отсортировать по номерам телефона
//• Вывести список пользователей
//• Выход

#include <stdio.h>
#include <locale.h>

#define MASS_SIZE 5

enum Menu
{
	SortICQNumbers = 1,
	SortMobileNumbers,
	PrintICQAndMobileUsers,
	Exit,
	Yes = 1,
	No
};

void menuCall(int* arrayForICQ, int* arrayForMobileNumbers);

void sortForICQNumbers(int* arrayForICQ, int* arrayForMobileNumbers);
void printICQNumbers(int* arrayForICQ);

void sortForMobileNumbers(int* arrayForICQ, int* arrayForMobileNumbers);
void printMobileNumbers(int* arrayForMobileNumbers);

int main()
{
	setlocale(LC_ALL, "Rus");
	int arrayForICQ[MASS_SIZE] = { 473166955, 823412495, 384012754, 562967483, 905738672 };
	int arrayForMobileNumbers[MASS_SIZE] = { 1234567, 4539716, 5693422, 2347895, 2342311 };
	printf("Добро пожаловать в справочник мобильных номеров и номеров в мессенджере ICQ.\n");
	menuCall(arrayForICQ, arrayForMobileNumbers);
}

void menuCall(int* arrayForICQ, int* arrayForMobileNumbers)
{
	printf("Выберите операцию:\n1. Сортировать номера ICQ.\n2. Сортировать мобильные номера.\n3. Вывести пользователей мобильных номеров и ICQ.\n"
		"4. Выход.\nСортировка производится по числовому возрастанию.\n");
	enum Menu chooseFunc;
	scanf("%i", &chooseFunc);
	switch (chooseFunc)
	{
	case SortICQNumbers:
		sortForICQNumbers(arrayForICQ, arrayForMobileNumbers);
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	case SortMobileNumbers:
		sortForMobileNumbers(arrayForMobileNumbers, arrayForMobileNumbers);
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	case PrintICQAndMobileUsers:
		printICQNumbers(arrayForICQ);
		printMobileNumbers(arrayForMobileNumbers);
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	case Exit:
		printf("До свидания.\n");
		exit(0);
		break;
	default:
		printf("Ошибка! Проверьте вводимую информацию.\n");
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	}
}

void sortForICQNumbers(int* arrayForICQ, int* arrayForMobileNumbers)
{
	int chisloDlaZameni;
	for (int i = 0; i < MASS_SIZE - 1; i++)
	{
		for (int j = 0; j < MASS_SIZE - 1 - i; j++)
		{
			if (arrayForICQ[j] > arrayForICQ[j + 1])
			{
				chisloDlaZameni = arrayForICQ[j];
				arrayForICQ[j] = arrayForICQ[j + 1];
				arrayForICQ[j + 1] = chisloDlaZameni;
			}
		}
	}	
	printf("Сортировка завершена. Вывести результат на экран?\n1. Да\n2. Нет\n");
	enum Menu makeAChoiseBetweenYesAndNo;
	scanf("%i", &makeAChoiseBetweenYesAndNo);
	switch (makeAChoiseBetweenYesAndNo)
	{
	case Yes:
		printICQNumbers(arrayForICQ);
		break;
	case No:
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	default:
		printf("Error!\n");
		sortForICQNumbers(arrayForICQ, arrayForMobileNumbers);
		break;
	}

}
void printICQNumbers(int* arrayForICQ)
{
	printf("Номера ICQ:\n");
	for (int l = 0; l < MASS_SIZE; l++)
	{
		printf("%i\n", arrayForICQ[l]);
	}
	printf("\n");
}

void sortForMobileNumbers(int* arrayForICQ, int* arrayForMobileNumbers)
{
	int chisloDlaZameni;
	for (int i = 0; i < MASS_SIZE - 1; i++)
	{
		for (int j = 0; j < MASS_SIZE - 1 - i; j++)
		{
			if (arrayForMobileNumbers[j] > arrayForMobileNumbers[j + 1])
			{
				chisloDlaZameni = arrayForMobileNumbers[j];
				arrayForMobileNumbers[j] = arrayForMobileNumbers[j + 1];
				arrayForMobileNumbers[j + 1] = chisloDlaZameni;
			}
		}
	}
	printf("Сортировка завершена. Вывести результат на экран?\n1. Да\n2. Нет\n");
	enum Menu makeAChoiseBetweenYesAndNo;
	scanf("%i", &makeAChoiseBetweenYesAndNo);
	switch (makeAChoiseBetweenYesAndNo)
	{
	case Yes:
		printMobileNumbers(arrayForMobileNumbers);
		break;
	case No:
		menuCall(arrayForICQ, arrayForMobileNumbers);
		break;
	default:
		printf("Error!\n");
		sortForMobileNumbers(arrayForMobileNumbers, arrayForMobileNumbers);
		break;
	}
}
void printMobileNumbers(int* arrayForMobileNumbers)
{
	printf("Мобильные номера:\n");
	for (int l = 0; l < MASS_SIZE; l++)
	{
		printf("%i\n", arrayForMobileNumbers[l]);
	}
	printf("\n");
}
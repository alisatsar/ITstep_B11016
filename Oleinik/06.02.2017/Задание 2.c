//Пользователь вводит прибыль фирмы за год(12 месяцев).Затем пользователь
//вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо
//определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль
//была минимальна с учетом выбранного диапазона.

#include <stdio.h>
#include <locale.h>

int funkciaDlaPodschetaMaxZnachenia(int massivPribileIliYbitkovPredpiiatia[], int nachaloDiapozonaPoiska, int konecDiapozonaPoiska);
int funkciaDlaPodschetaMinZnachenia(int massivPribileIliYbitkovPredpiiatia[], int nachaloDiapozonaPoiska, int konecDiapozonaPoiska);


int main()
{
	int massivPribileIliYbitkovPredpiiatia[12];
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < 12; i++)
	{
		printf("Введите пожалуйста доход за %i месяц : ", i + 1);
		massivPribileIliYbitkovPredpiiatia[i];
		scanf("%i", &massivPribileIliYbitkovPredpiiatia[i]);
	}


	int nachaloDiapozonaPoiska;
	int konecDiapozonaPoiska;
	printf("Задайте начало диапозона: ");
	scanf("%i", &nachaloDiapozonaPoiska);
	printf("Задайте конец диапозона: ");
	scanf("%i", &konecDiapozonaPoiska);
	if (nachaloDiapozonaPoiska < 1 || nachaloDiapozonaPoiska > 12 || konecDiapozonaPoiska > 12 || konecDiapozonaPoiska < 1)
	{
		printf("Ошибка ввода значений.\n");
		return 0;
	}
	else if (nachaloDiapozonaPoiska > konecDiapozonaPoiska)
	{
		printf("Мы обнаружили, что начало диапозона больше его конца. Зачения были исправлены в ходе программы местами.\n");
		int chisloDlaZameniMestami = nachaloDiapozonaPoiska;
		nachaloDiapozonaPoiska = konecDiapozonaPoiska;
		konecDiapozonaPoiska = chisloDlaZameniMestami;
	}
	
	printf("Максимальная прибыль за данный период была: %i\n", funkciaDlaPodschetaMaxZnachenia(massivPribileIliYbitkovPredpiiatia, nachaloDiapozonaPoiska, konecDiapozonaPoiska));

	printf("Минимальная прибыль за данный период была: %i\n", funkciaDlaPodschetaMinZnachenia(massivPribileIliYbitkovPredpiiatia, nachaloDiapozonaPoiska, konecDiapozonaPoiska));
}

int funkciaDlaPodschetaMaxZnachenia(int massivPribileIliYbitkovPredpiiatia[], int nachaloDiapozonaPoiska, int konecDiapozonaPoiska)
{
	int max = massivPribileIliYbitkovPredpiiatia[nachaloDiapozonaPoiska];
	for (int i = nachaloDiapozonaPoiska - 1; i < konecDiapozonaPoiska; i++)
	{
		if (max < massivPribileIliYbitkovPredpiiatia[i])
		{
			max = massivPribileIliYbitkovPredpiiatia[i];
		}
	}
	return max;
}

int funkciaDlaPodschetaMinZnachenia(int massivPribileIliYbitkovPredpiiatia[], int nachaloDiapozonaPoiska, int konecDiapozonaPoiska)
{
	int min = massivPribileIliYbitkovPredpiiatia[nachaloDiapozonaPoiska];
	for (int i = nachaloDiapozonaPoiska - 1; i < konecDiapozonaPoiska; i++)
	{
		if (min > massivPribileIliYbitkovPredpiiatia[i])
		{
			min = massivPribileIliYbitkovPredpiiatia[i];
		}
	}
	return min;
}
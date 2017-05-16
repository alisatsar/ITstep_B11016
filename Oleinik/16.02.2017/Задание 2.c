//Создайте двухмерный массив.Заполните его случайными числами и покажите
//на экран.
//Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).
//Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum ShiftPosition
{
	Right = 1,
	Left,
	Top = 1,
	Bottom,
	BothOfThem
};

#define MASSIV_COLUMN 2
#define MASSIVS_ROW 5

void getLeftShift(int massiv[MASSIV_COLUMN][MASSIVS_ROW], int sdvig, int shiftMassivLevel, int stopForShiftMassivLevel);
void getRightShift(int massiv[MASSIV_COLUMN][MASSIVS_ROW], int sdvig, int shiftMassivLevel, int stopForShiftMassivLevel);

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	printf("Программа выполнит сдвиг ряда массива на значение, введенное вами.\n"
		"Плюс ко всему, будет предоставлена возможность выбрать направление сдвига и уровень на котором произойдёт.\n"
		"Исходный массив будет иметь следующий вид:\n");
	int massiv[MASSIV_COLUMN][MASSIVS_ROW];
	for (int i = 0; i < MASSIV_COLUMN; i++)
	{
		for (int l = 0; l < MASSIVS_ROW; l++)
		{
			massiv[i][l] = rand() % 10;
			printf("%i ", massiv[i][l]);
		}
		printf("\n");
	}
	printf("Введите величину сдвига (сдвиг не должен быть больше велечины массива): ");
	int sdvig = 0;
	scanf("%i", &sdvig);
	if (sdvig > MASSIVS_ROW)
	{
		printf("Мы думаем, что это слишком большое число.\nЗасчитаем его как 4.\n");
		sdvig = 4;
	}
	else if (sdvig < 0)
	{
		printf("Мы думаем, что это слишком маленькое число.\nЗасчитаем его как 2.\n");
		sdvig = 4;
	}
	enum ShiftPosition topOrButtomShft;
	int shiftMassivLevel;
	int stopForShiftMassivLevel;
	printf("Какой уровень массива будем сдвигать?\nВерхний уровень(1), нижний уровень(2), оба уровня(3): ");
	scanf("%i", &topOrButtomShft);
	switch (topOrButtomShft)
	{
	case Top:
		shiftMassivLevel = 0;
		stopForShiftMassivLevel = 1;
		break;
	case Bottom:
		shiftMassivLevel = 1;
		stopForShiftMassivLevel = 2;
		break;
	case BothOfThem:
		shiftMassivLevel = 0;
		stopForShiftMassivLevel = 2;
		break;
	default:
		printf("Ошибка. Повторите ввод.");
		return 0;
		break;
	}
	printf("В какую стороную производим сдвиг?\nВправо(1) или Влево(2): ");
	enum ShiftPosition shiftPositionRightOrLeft;
	scanf("%i", &shiftPositionRightOrLeft);
	switch (shiftPositionRightOrLeft)
	{
	case Right:
		getRightShift(massiv, sdvig, shiftMassivLevel, stopForShiftMassivLevel);
		break;
	case Left:
		getLeftShift(massiv, sdvig, shiftMassivLevel, stopForShiftMassivLevel);
		break;
	default:
		printf("Ошибка. Повторите ввод.");
		return 0;
		break;
	}
}

void getLeftShift(int massiv[MASSIV_COLUMN][MASSIVS_ROW], int sdvig, int shiftMassivLevel, int stopForShiftMassivLevel)
{
	printf("Сдвиг влево.\n");
	if (shiftMassivLevel == 1 && stopForShiftMassivLevel == 2)
	{
		for (int o = 0; o < 5; o++)
		{
			printf("%i ", massiv[0][o]);
		}
		printf("\n");
	}
	for (int m = shiftMassivLevel; m < stopForShiftMassivLevel; m++)
	{
		for (int j = 0 + sdvig; j < MASSIVS_ROW; j++)
		{
			printf("%i ", massiv[m][j]);

		}
		for (int k = 0; k < sdvig; k++)
		{
			printf("%i ", massiv[m][k]);
		}
		printf("\n");
	}
	if (shiftMassivLevel == 0 && stopForShiftMassivLevel == 1)
	{
		for (int o = 0; o < 5; o++)
		{
			printf("%i ", massiv[1][o]);
		}
		printf("\n");
	}
}

void getRightShift(int massiv[MASSIV_COLUMN][MASSIVS_ROW], int sdvig, int shiftMassivLevel, int stopForShiftMassivLevel)
{
	printf("Сдвиг вправо.\n");
	int p = 1;
	for (int m = shiftMassivLevel; m < stopForShiftMassivLevel; m++)
	{
		for (int j = sdvig; j > 0; j--)
		{
			printf("%i ", massiv[m][MASSIVS_ROW - j]);

		}
		for (int k = 0; k < sdvig + 1; k++)
		{
			printf("%i ", massiv[m][k]);
		}
		printf("\n");
	}
	
	if (shiftMassivLevel == 0 && stopForShiftMassivLevel == 1)
	{
		for (int o = 0; o < 5; o++)
		{
			printf("%i ", massiv[1][o]);
		}
		printf("\n");
	}
}
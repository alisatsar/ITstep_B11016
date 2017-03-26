//Задание 2
//Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и
//играющий должен угадать его.После ввода пользователем числа программа сообщает,
//сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте
//(коровы).После отгадывания числа на экран необходимо вывести количество сделанных
//пользователем попыток.В программе необходимо использовать рекурсию.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MASS_SIZE_DLA_RAZDELENIIA 4

int funkciiaBikiiKorovi(int razdelenieChislaComputeralNaSostovlaushie[], int razdelenieChislaUseralNaSostovlaushie[], int chisloZagadannoeComputerom[], int usersChislo[]);
int funkciiaDlaRazdelenieChislaComputeralNaSostovlaushie(int chisloZagadannoeComputerom[], int razdelenieChislaComputeralNaSostovlaushie[]);
int funkciiaDlaRazdelenieChislaUseralNaSostovlaushie(int razdelenieChislaUseralNaSostovlaushie[], int razdelenieChislaComputeralNaSostovlaushie[], int usersChislo[]);

int countDlaPodschetaPovtoraFuncii = 1;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	printf("Игра быки и коровы. Компьтер загадывает четырёхзначное число и вы должны угадать его.\nПрограмма будет подсказывать вам, сколько цифр вы отгадали и какое из них соответствует в загаданном числе.\n");
	int usersChislo[1];
	int razdelenieChislaUseralNaSostovlaushie[4];
	int razdelenieChislaComputeralNaSostovlaushie[MASS_SIZE_DLA_RAZDELENIIA];
	int chisloZagadannoeComputerom[1] = { 1000 + rand() % 9000 };
	printf("%i\n", chisloZagadannoeComputerom[0]);
	printf("Поздравляю, вы отгадали число. Колличество произведенных попыток: %i.\n", funkciiaBikiiKorovi(razdelenieChislaComputeralNaSostovlaushie, razdelenieChislaUseralNaSostovlaushie, chisloZagadannoeComputerom, usersChislo));
}

int funkciiaDlaRazdelenieChislaComputeralNaSostovlaushie(int chisloZagadannoeComputerom[], int razdelenieChislaComputeralNaSostovlaushie[])
{
	razdelenieChislaComputeralNaSostovlaushie[0] = chisloZagadannoeComputerom[0] % 10000 / 1000;
	razdelenieChislaComputeralNaSostovlaushie[1] = chisloZagadannoeComputerom[0] % 1000 / 100;
	razdelenieChislaComputeralNaSostovlaushie[2] = chisloZagadannoeComputerom[0] % 100 / 10;
	razdelenieChislaComputeralNaSostovlaushie[3] = chisloZagadannoeComputerom[0] % 10;
	return razdelenieChislaComputeralNaSostovlaushie;
}

int funkciiaDlaRazdelenieChislaUseralNaSostovlaushie(int razdelenieChislaUseralNaSostovlaushie[], int razdelenieChislaComputeralNaSostovlaushie[], int usersChislo[])
{
	scanf("%i", &usersChislo[0]);
	if (usersChislo[0] > 9999 || usersChislo[0] < 1000)
	{
		printf("Введённое число не соответствует требованием игры. Повторите ввод.\n");
		return 0;
	}
	else
	{
		razdelenieChislaUseralNaSostovlaushie[0] = usersChislo[0] % 10000 / 1000;
		razdelenieChislaUseralNaSostovlaushie[1] = usersChislo[0] % 1000 / 100;
		razdelenieChislaUseralNaSostovlaushie[2] = usersChislo[0] % 100 / 10;
		razdelenieChislaUseralNaSostovlaushie[3] = usersChislo[0] % 10;
	}
	return razdelenieChislaUseralNaSostovlaushie;
}

int funkciiaBikiiKorovi(int razdelenieChislaComputeralNaSostovlaushie[], int razdelenieChislaUseralNaSostovlaushie[], int chisloZagadannoeComputerom[], int usersChislo[])
{
	
	printf("Вводите число: ");
	funkciiaDlaRazdelenieChislaUseralNaSostovlaushie(razdelenieChislaUseralNaSostovlaushie, razdelenieChislaComputeralNaSostovlaushie, usersChislo);
	funkciiaDlaRazdelenieChislaComputeralNaSostovlaushie(chisloZagadannoeComputerom, razdelenieChislaComputeralNaSostovlaushie);

	int countDlaKorov = 0;
	for (int i = 0; i < MASS_SIZE_DLA_RAZDELENIIA; i++)
	{
		if (razdelenieChislaUseralNaSostovlaushie[0] == razdelenieChislaComputeralNaSostovlaushie[i])
		{
			countDlaKorov++;
		}
		if (razdelenieChislaUseralNaSostovlaushie[1] == razdelenieChislaComputeralNaSostovlaushie[i])
		{
			countDlaKorov++;
		}
		if (razdelenieChislaUseralNaSostovlaushie[2] == razdelenieChislaComputeralNaSostovlaushie[i])
		{
			countDlaKorov++;
		}
		if (razdelenieChislaUseralNaSostovlaushie[3] == razdelenieChislaComputeralNaSostovlaushie[i])
		{
			countDlaKorov++;
		}
	}

	printf("Число угаданых чисел: %i\n", countDlaKorov);

	int countDlaBikov = 0;
	for (int j = 0; j < MASS_SIZE_DLA_RAZDELENIIA; j++)
	{
		if (razdelenieChislaUseralNaSostovlaushie[j] == razdelenieChislaComputeralNaSostovlaushie[j])
		{
			printf("%i цифра вашего числа соответствует %i цифре загаданного числа.\n", j + 1, j + 1);
			countDlaBikov++;
		}	
	}
	if (usersChislo[0] != chisloZagadannoeComputerom[0])
	{
		funkciiaBikiiKorovi(razdelenieChislaComputeralNaSostovlaushie, razdelenieChislaUseralNaSostovlaushie, chisloZagadannoeComputerom, usersChislo);
		countDlaPodschetaPovtoraFuncii++;
	}
	else if (countDlaBikov == MASS_SIZE_DLA_RAZDELENIIA)
	{
		return countDlaPodschetaPovtoraFuncii;
	}
}
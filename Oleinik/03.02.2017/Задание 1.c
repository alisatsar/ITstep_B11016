//Задание 1
//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых
//чисел.

#include <stdio.h>
#include <locale.h>

int funkciaNahozhdeniaObchegoDelitela(int pervoeChisloOtPolzovatela, int vtoroeChisloOtPolzovatela);


int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Первое число: ");
	float pervoeChisloOtPolzovatela;
	scanf("%f", &pervoeChisloOtPolzovatela);
	printf("Второе число: ");
	float vtoroeChisloOtPolzovatela;
	scanf("%f", &vtoroeChisloOtPolzovatela);
	funkciaNahozhdeniaObchegoDelitela(pervoeChisloOtPolzovatela, vtoroeChisloOtPolzovatela);
	printf("%i\n", funkciaNahozhdeniaObchegoDelitela(pervoeChisloOtPolzovatela, vtoroeChisloOtPolzovatela));
}

int funkciaNahozhdeniaObchegoDelitela(int pervoeChisloOtPolzovatela, int vtoroeChisloOtPolzovatela)
{
	while (pervoeChisloOtPolzovatela != 0 && vtoroeChisloOtPolzovatela != 0)
	{
		if (pervoeChisloOtPolzovatela > vtoroeChisloOtPolzovatela)
		{
			pervoeChisloOtPolzovatela = pervoeChisloOtPolzovatela % vtoroeChisloOtPolzovatela;
			printf("pervoeChisloOtPolzovatela %i\n", pervoeChisloOtPolzovatela);
		}
		else
		{
			vtoroeChisloOtPolzovatela = vtoroeChisloOtPolzovatela % pervoeChisloOtPolzovatela;
			printf("vtoroeChisloOtPolzovatela %i\n", vtoroeChisloOtPolzovatela);
		}
	}
	return pervoeChisloOtPolzovatela + vtoroeChisloOtPolzovatela;
}
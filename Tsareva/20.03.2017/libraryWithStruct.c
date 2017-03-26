/*Задание 1:
Разработать программу для управления библиотекой книг(имя, автор, жанр, год) со
следующими возможностями :
• Добавление книг
• Вывод списка книг
• Сортировка по заданному критерию(имя, автор, жанр, год) с указанием
направления сортировки*/

#include <stdio.h>
#include <string.h>

#define SIZE_NAME 40
#define SIZE_AUTHOR 50
#define SIZE_GENRE 35
#define COUNT_BOOK 10

enum Menu
{
	AddNewBook = 1,
	PrintBook = 2,
	SortBooks = 3,
	Quit = 4
};

enum TypeSort
{
	Name = 1,
	Author = 2,
	Gente = 3,
	Year = 4
};

struct Books
{
	char Name[SIZE_NAME];
	char Author[SIZE_AUTHOR];
	char Genre[SIZE_GENRE];
	int Year;
};

void addBook(struct Books* library, int count, int* counterBooks);
void printBooks(struct Books* library, int counterBook);
void cleanInput();
int bookCompare(struct Books* book1, struct Books* book2, enum TypeSort typeSort);
void sortLibrary(struct Books books[COUNT_BOOK], int counterBooks);

int main()
{
	struct Books library[COUNT_BOOK];
	enum Menu menu;
	
	int counterBooks = 0;

	while (1)
	{
		printf("Please, enter what you want to do: \n");
		printf("1 - Add New book\n");
		printf("2 - Print books\n");
		printf("3 = Sort books\n");
		printf("4 - Quit\n");

		scanf_s("%i", &menu);

		cleanInput();

		switch (menu)
		{
		case AddNewBook:
			addBook(library, COUNT_BOOK, &counterBooks);
			break;
		case PrintBook:
			printBooks(library, counterBooks);
			break;
		case SortBooks:
			sortLibrary(library, counterBooks);
			break;
		case Quit:
			return 0;
		}
	}
}

void addBook(struct Books* library, int count, int* counterBooks)
{
	if (*counterBooks < count)
	{
		printf("Enter name: ");
		fgets(library[*counterBooks].Name, SIZE_NAME, stdin);
		printf("Enter author: ");
		fgets(library[*counterBooks].Author, SIZE_AUTHOR, stdin);
		printf("Enter genre: ");
		fgets(library[*counterBooks].Genre, SIZE_GENRE, stdin);
		printf("Enter year: ");
		scanf("%i", &library[*counterBooks].Year);
		*counterBooks += 1;
	}
}

void cleanInput()
{
	char ch;
	do
	{
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

void printBooks(struct Books* library, int counterBook)
{
	for (int i = 0; i < counterBook; i++)
	{
		printf("_________________\n");
		printf("Book %i: \n", i + 1);
		printf("Name: %s", library[i].Name);
		printf("Author: %s", library[i].Author);
		printf("Genre: %s", library[i].Genre);
		printf("Years: %i\n", library[i].Year);
	}
}

void sortLibrary(struct Books books[COUNT_BOOK], int counterBooks)
{
	enum TupeSort typeSort;

	printf("Choose the category for sort books: \n");
	printf("1 = Name\n2 = Author\n3 = Gente\n4 = Year\n");

	scanf_s("%i", &typeSort);
	cleanInput();

	for (int i = 0; i < counterBooks - 1; i++)
	{
		for (int j = 0; j < counterBooks - i - 1; j++)
		{
			if (bookCompare(&books[j], &books[j + 1], typeSort))
			{
				struct Books tmp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = tmp;
			}
		}
	}
}

int bookCompare(struct Books* book1, struct Books* book2, enum TypeSort typeSort)
{
	switch (typeSort)
	{
	case Name:
		return strcmp((*book1).Name, (*book2).Name);
		break;
	case Author:
		return strcmp(book1->Author, book2->Author);
		break;
	case Gente:
		return strcmp(book1->Genre, book2->Genre);
		break;
	case Year:
		return strcmp(book1->Year, book2->Year);
		break;
	}
}

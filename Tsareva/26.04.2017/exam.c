#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>

#define TEXT_SIZE 256
#define NAME_SIZE 100
#define FILE_NAME_SIZE 130

enum Menu
{
	AddRecipe = 1,
	ViewRecipe,
	EditRecipe,
	DeleteRecipe,
	ExitFromProgram
};

struct Recipe
{
	char Name[NAME_SIZE];
	char Text[TEXT_SIZE];
	int Rating;
};

void addRecipe();
void cleanInput();
void convertRecipeNameinFileName(char* buff);
void viewAllRecipe(char* fileName, bool* showDataCreateFile);
void viewRecipe();
void editRecipe();
void deleteRecipe();

int main()
{
	enum Menu menu = 0;

	while (menu != 5)
	{
		do
		{
			printf("Please enter what you want to do:\n");
			printf("1 - Add recipe\n2 - View recipe\n3 - Edit recipe\n4 - Delete Recipe\n5 - Exit from program\n");
 			scanf("%i", &menu);
		} while (menu < 1 || menu > 5);
		
		switch (menu)
		{
		case AddRecipe:
			addRecipe();
			break;
		case ViewRecipe:
			viewRecipe();
			break;
		case EditRecipe:
			editRecipe();
			break;
		case DeleteRecipe:
			deleteRecipe();
			break;
		case ExitFromProgram:
			return 0;
			break;
		}
	}
}

void addRecipe()
{
	cleanInput();
	struct Recipe recipe;
	char buff[NAME_SIZE];

	memset(recipe.Name, 0, NAME_SIZE);
	memset(recipe.Text, 0, TEXT_SIZE);
	recipe.Rating = 0;
	
	printf("_______________ADD NEW FILE_______________\n");
	printf("Enter the name of recipe: \n");
	fgets(recipe.Name, NAME_SIZE, stdin);
	memset(buff, 0, NAME_SIZE);
	strcpy(buff, recipe.Name);
	convertRecipeNameinFileName(buff);

	char fileName[FILE_NAME_SIZE] = "d:\\\\recipe\\\\";
	strcat(fileName, buff);
	strcat(fileName, ".recipe");

	FILE* file = fopen(fileName, "wb");
	
	printf("Enter the text of recipe: \n");
	fgets(recipe.Text, TEXT_SIZE, stdin);
		
	while (recipe.Rating < 1 || recipe.Rating > 10)
	{
		printf("Enter the rating of recipe: \n");
		scanf("%i", &recipe.Rating);
	}
	cleanInput();

	fseek(file, 0, SEEK_SET);
	fwrite(&recipe, sizeof(struct Recipe), 1, file);

	fclose(file);
}

void convertRecipeNameinFileName(char* buff)
{
	char* find;
	char* findSpace;

	if (buff)
	{
		do
		{
			findSpace = 0;
			find = strchr(buff, '\n');
			findSpace = strchr(buff, ' ');
			if (find)
			{
				*find = 0;
			}
			if (findSpace)
			{
				*findSpace = '_';
			}
		} while (findSpace != NULL);
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

void viewAllRecipe(char* fileName, bool* showDataCreateFile)
{
	cleanInput();
	WIN32_FIND_DATAA found;
	HANDLE findResult = FindFirstFileA("d:\\recipe\\*.recipe", &found);
	
	int numberOfFile;
	
	printf("_______________ALL FILES_______________\n");

	if (findResult == INVALID_HANDLE_VALUE)
	{
		printf("This directory contains no files\n");
	}
	else
	{
		int countFile = 0;
		do
		{
			if ((found.nFileSizeHigh * (MAXDWORD + 1)) + found.nFileSizeLow != 0)
			{
				printf("%i - %s\n", countFile + 1, found.cFileName);
				countFile = countFile + 1;
			}
		} while (FindNextFileA(findResult, &found));

		char** arrayFileName = calloc(countFile, sizeof(char*));

		findResult = FindFirstFileA("d:\\recipe\\*.recipe", &found);

		countFile = 0;
		do
		{
			if (found.nFileSizeLow != NULL)
			{
				arrayFileName[countFile] = calloc(100, sizeof(char));
				strcpy(*(arrayFileName + countFile), found.cFileName);
				countFile = countFile + 1;
			}
		} while (FindNextFileA(findResult, &found));
	
		do
		{
			printf("Enter the number of file name: ");
			scanf("%i", &numberOfFile);
		} while (numberOfFile < 1 || numberOfFile > countFile);
		cleanInput();
		
		strcat(fileName, arrayFileName[numberOfFile - 1]);
				
		if (*showDataCreateFile == true)
		{
			printf("_______________VIEW FILE %s_______________\n", fileName);
			findResult = FindFirstFileA("d:\\recipe\\*.recipe", &found);
			do
			{
				if (strcmp(found.cFileName, arrayFileName[numberOfFile - 1]) == 0)
				{
					SYSTEMTIME time;
					FileTimeToSystemTime(&found.ftLastAccessTime, &time);
					printf("\nThe creation date of the recipe: ");
					printf("[%d.%d.%d]\n", time.wDay, time.wMonth, time.wYear);
				}
			} while (FindNextFileA(findResult, &found));
		}
	}
	FindClose(findResult);
}

void viewRecipe()
{
	char fileName[FILE_NAME_SIZE] = "d:\\\\recipe\\\\";
	struct Recipe recipe;
	bool showDataCreateFile = true;

	viewAllRecipe(fileName, &showDataCreateFile);

	FILE* file = fopen(fileName, "rb");

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		fread(&recipe, sizeof(struct Recipe), 1, file);
		printf("Recipe's name: ");
		printf("%s", recipe.Name);
		printf("Recipe's text: ");
		printf("%s", recipe.Text);
		printf("Recipe's rating: ");
		printf("%i\n\n", recipe.Rating);
	}
	fclose(file);
}

void editRecipe()
{
	char fileName[FILE_NAME_SIZE] = "d:\\\\recipe\\\\";
	struct Recipe recipe;
	bool showDataCreateFile = false;

	viewAllRecipe(fileName, &showDataCreateFile);

	FILE* file = fopen(fileName, "rb");

	printf("_______________EDIT FILE %s_______________\n", fileName);

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		fread(&recipe, sizeof(struct Recipe), 1, file);
		memset(recipe.Text, 0, TEXT_SIZE);
		printf("Enter the text of recipe: ");
		fgets(recipe.Text, TEXT_SIZE, stdin);
		file = fopen(fileName, "wb");
		fwrite(&recipe, sizeof(struct Recipe), 1, file);
	}
	fclose(file);
}

void deleteRecipe()
{
	bool showDataCreateFile = false;
	char fileName[FILE_NAME_SIZE];

	memset(fileName, 0, FILE_NAME_SIZE);
	strcpy(fileName, "d:\\\\recipe\\\\");

	viewAllRecipe(fileName, &showDataCreateFile);

	FILE* file = fopen(fileName, "wb");

	if (file == NULL)
	{
		printf("This file is not found");
	}
	else
	{
		fclose(file);
		unsigned int rc = remove(fileName);
		if (rc)
		{ 
			printf("Removed %s\n", fileName);
		}
	}
}
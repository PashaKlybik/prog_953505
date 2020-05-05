#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>

int main()
{
	int countOfSpaces;
	FILE *f, *fHelper;
	char s[80], space = ' ';
	fopen_s(&f, "laba4_2.txt", "r");
	fopen_s(&fHelper, "laba4_2_helper.txt", "w");

	if (f == 0 && fHelper == 0)
	{
		printf_s("just get stepout the window");
	}
	else
	{
		printf_s("alright! *opening beer* \n");
	}


	while ((fgets(s, 80, f)) != NULL)
	{
		countOfSpaces = (80 - strlen(s)) / 2;
		for (int i = 0; i < countOfSpaces; i++)
		{
			fputc(32, fHelper);
		}
		fputs(s, fHelper);
	}



	fclose(f);
	fclose(fHelper);
}

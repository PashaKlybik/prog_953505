#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <cstdlib>

#include "List.h"

#define PRIME_SIZE 29

typedef struct Article
{

}Article;

typedef struct SourceCode
{

}SourceCode;

typedef struct Comment
{

}Comment;

typedef struct Page
{
	Article* article;
	SourceCode* sourceCode;
	List commets;


}Page;



sturct Account
{
	char name[20];
	long long passwordHash;
}Account;

int Login(char name[20], char password[30])
{
	const int p = 31;
	long long hash = 0, p_pow = 1;
	if (strcmp(name, Account.name) == 0)
	while(password[i] != 0)
	{
		hash += (s[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
}

int Logout()
{

}
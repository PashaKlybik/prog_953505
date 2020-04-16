#include <stdlib.h>
#include <stdio.h>
#include <string>

int main()
{
	char str[80];
	FILE *fin;
	fopen_s(&fin, "laba.txt", "r");
	fgets(str, 80, fin);
	fprintf(stdout, "%s", str);
	fclose(fin);

}


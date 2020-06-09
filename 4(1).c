#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct counter_pair {
	int symbol_count;
	int code;
};

int main() {

	int i = 0, len;

	struct counter_pair cp[5];
	char str[1024];
	char* rc;
	cp[++i].code = 'u';
	cp[++i].code = 'i';
	cp[++i].code = 'o';
	cp[i].code = 'a';
	cp[++i].code = 'e';

	for (i = 0; i < 5; i++)
	{
		cp[i].symbol_count = 0;
	}

	printf("Input string: ");
	rc = fgets(str, 1023, stdin);


	len = strlen(str);
	for (i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (cp[j].code == str[i]) {
				cp[j].symbol_count += 1;
			}
		}
	}



	printf("Table\n");
	for (i = 0; i < 5; i++) {
		if (cp[i].symbol_count == 0) continue;
		printf("symbol %c was %d Times\n", cp[i].code, cp[i].symbol_count);
	}
	getch();
	return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// var 2
void Assignment1(){
	const int stLength = 256;
	char str[256];
	printf("String: ");
	gets_s(str,255);
	int addSpaces = 0;
	for (int i = 0; i < stLength - 1; i++) {
		if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':'  || str[i] == '!' || str[i] == '?') {
			
			
			if (str[i + 1]  != ' ') {
				addSpaces++;
			}
		}
	
	}
	char* newStr = malloc((stLength + addSpaces) * sizeof(char));
	for (int i = 0,j = 0; i < stLength + addSpaces; i++,j++) {
		
		newStr[j] = str[i];
		
		if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '!' || str[i] == '?') {

			
			if (str[i + 1] != ' ') {
				newStr[j + 1] = ' ';
				j++;
				if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
					if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
						newStr[j + 1] = str[i + 1] + ('A' - 'a');
						j++;
						i++;
					}
				}

			}
			else if (str[i + 1] == ' ' ) {
				newStr[j + 1] = ' ';
				j++;
				i++;
				if (str[i -1 ] == '.' || str[i - 1] == '!' || str[i - 1] == '?') {
					if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
						newStr[j + 1] = str[i + 1] + ('A' - 'a');
						j++;
						i++;
					}
				}
			}


		}
	}
	
	
	
	
	printf("%s", newStr);
}
int GetStringLength(char *str) {
	int length = 0;
	for (int i = 0; ; i++) {
		if (str[i] == '\n' || str[i] == '\0') {
			break;
		}
		length++;
	}
	return length;
}
void Assignment2() {
	FILE* fl;
	char st[256];
	st[255] = '\0';
	fl = fopen("C:\\Users\\admin\\Desktop\\C\\lab4\\lab4\\test.txt", "r");
	
	fgets(st,256,fl);
	puts(st);
	int parenthesisCounter = 0;
	int strLength = GetStringLength(st);
	for (int i = 0; i < strLength; i++) {
		
		if (st[i] == '(') {
			parenthesisCounter++;
		}
		else if (st[i] == ')') {
			parenthesisCounter--;
		}
		else {
			printf("Soomething besides the parenthesis in the string");
			return;
		}
		if (parenthesisCounter < 0) {
			printf("Parenthesis are in the wrong order");
			return;
		}
		
	}
	if (parenthesisCounter > 0) {
		printf("Parenthesis are in the wrong order");
		return;
	}
	rewind(fl);
	
	for (int i = 0; i < strLength; i++) {
		if (st[i] == '(') {
			parenthesisCounter++;
			if (parenthesisCounter == 2) {
				st[i] = '[';
			}
			else if (parenthesisCounter >= 3) {
				st[i] = '{';
			}
		}
		else if (st[i] == ')') {
			parenthesisCounter--;
			if (parenthesisCounter == 1) {
				st[i] = ']';
			}
			else if (parenthesisCounter >= 2) {
				st[i] = '}';
			}
		}
		
	}
	puts(st);
	fclose(fl);
	fl = fopen("C:\\Users\\admin\\Desktop\\C\\lab4\\lab4\\test.txt", "w");
	fputs(st,fl);
	
}
//var 2
int main() {
	//Assignment1();
	Assignment2();
	return 0;
}
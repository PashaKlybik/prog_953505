#include "work_with_files.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
void ShowAllFromFile(List* list, FILE* fPtr) {
	//system("cls");
	errno_t err;
	Flight temp;
	if ((err = fopen_s(&fPtr, "flights.dat", "r")) != 0) {
		printf("\n%s", "Global Fail...");
	}
	else {
		fseek(fPtr, 0, 0);
		fread(&temp, sizeof(Flight), 1, fPtr);
		while (!feof(fPtr)) {
			PrintFlight(temp);
			fread(&temp, sizeof(Flight), 1, fPtr);
		}
		fclose(fPtr);
	}
}
void LoadFromFileToList(List* list) {
		errno_t err;	
		FILE* fPtr;
		if ((err = fopen_s(&fPtr, "flights.dat", "r")) != 0) {
			printf("\n%s", "Global Fail...");
		}
		else {
			fseek(fPtr, 0, 0);
			Flight temp;
			fread(&temp, sizeof(Flight), 1, fPtr);
			while (!feof(fPtr)) {
				AddFlight(list, &temp);
				fread(&temp, sizeof(Flight), 1, fPtr);
			}
			fclose(fPtr);
		}
}
void LoadToFile(Flight* flight) {
	if (&flight == NULL)return;
	errno_t err;
	FILE* fPtr;
	if ((err = fopen_s(&fPtr, "flights.dat", "r+")) != 0) {
		printf("\n%s", "Global Fail...");
	}
	else {
		Flight* temp = (Flight*)malloc(sizeof(Flight));
		memcpy(temp, flight, sizeof(Flight));
		fseek(fPtr, 0, SEEK_END);
		fwrite(temp, sizeof(Flight), 1, fPtr);
		fclose(fPtr);
	}
}
/*!!! NOT FOR USE !!!*/
void CreateFileWithFlights() {
	errno_t err;
	FILE *fPtr;
	Flight temp0 = { 0,"LN32","London","B737",12,30,5,70,August,30 };
	Flight temp1 = { 1,"BR322","Berlin","B737",5,30,4,110,July,1 };
	Flight temp2 = { 2,"LN32","London","B737",18,00,5,30,July,15 };
	Flight temp3 = { 3,"MS137","Moscow","B747",4,30,2,200,August,13 };
	Flight temp4 = { 4,"PL1","Warsaw","B747",5,30,2,110,July,1 };
	Flight temp5 = { 5,"LN800","London","B747",17,00,4,30,October,4 };
	Flight temp6 = { 6,"PA300","Paris","B777",2,20,7,78,October,30 };
	Flight temp7 = { 7,"MA999","Madrid","B777",23,00,9,45,November,1 };
	if ((err = fopen_s(&fPtr, "flights.dat", "w")) != 0) {
		return;	
	}
	else {
		fwrite(&temp0, sizeof(Flight), 1, fPtr);
		fwrite(&temp1, sizeof(Flight), 1, fPtr);
		fwrite(&temp2, sizeof(Flight), 1, fPtr);
		fwrite(&temp3, sizeof(Flight), 1, fPtr);
		fwrite(&temp4, sizeof(Flight), 1, fPtr);
		fwrite(&temp5, sizeof(Flight), 1, fPtr);
		fwrite(&temp6, sizeof(Flight), 1, fPtr);
		fwrite(&temp7, sizeof(Flight), 1, fPtr);
		fclose(fPtr);
	}
}

// Lab4.2.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <Windows.h>
#define LONG_STR 80

struct WordInfo {
	char* word;
};

struct Vocabulary {
	int countwords;
	WordInfo* words;
	int countpalindroms;
	WordInfo* palindroms;
};

void InitializeVocabulary(Vocabulary* voc) {
	voc->countwords = 0;
	voc->words = NULL;
	voc->countpalindroms = 0;
	voc->palindroms = NULL;
}

int IsStringPalindrom(const char* line) {
	int linelen = strlen(line);
	if (linelen < 2) {
		return 0;
	}
	for (int i = 0; i < linelen / 2; i++) {
		if (line[i] != line[linelen - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

//int WordInfoCompareByRepeatsDesc(const void* wordinfo1, const void* wordinfo2) {
//	return ((WordInfo*)wordinfo2)->repeats - ((WordInfo*)wordinfo1)->repeats;
//}


void FreeVocabulary(Vocabulary* voc) {
	for (int i = 0; i < voc->countpalindroms; i++) {
		free(voc->palindroms[i].word);
	}
	free(voc->palindroms);
	for (int i = 0; i < voc->countwords; i++) {
		free(voc->words[i].word);
	}
	free(voc->words);
	InitializeVocabulary(voc);
}



void UpdateVocabularyWords(Vocabulary* voc, const char* word) {
	for (int i = 0; i < voc->countwords; i++) {
		if (!strcmp(word, voc->words[i].word)) {
			return;
		}
	}
	WordInfo wordinfo;
	wordinfo.word = _strdup(word);

	voc->countwords++;
	voc->words = (WordInfo*)realloc(voc->words, voc->countwords * sizeof(WordInfo));
	
	voc->words[voc->countwords - 1] = wordinfo;

}

void UpdateVocabularyPalindroms(Vocabulary* voc, const char* word) {
	if (!IsStringPalindrom(word)) {
		return;
	}
	for (int i = 0; i < voc->countpalindroms; i++) {
		if (!strcmp(word, voc->palindroms[i].word)) {
			return;
		}
	}
	WordInfo wordinfo;
	wordinfo.word = _strdup(word);

	voc->countpalindroms++;
	voc->palindroms = (WordInfo*)realloc(voc->palindroms, voc->countpalindroms * sizeof(WordInfo));
	
	voc->palindroms[voc->countpalindroms - 1] = wordinfo;

}

int WordInfoCompareByWordAsc(const void* wordinfo1, const void* wordinfo2) {
	return strcmp(((WordInfo*)wordinfo1)->word, ((WordInfo*)wordinfo2)->word);
}

void UpdateAndPrintPalindroms(Vocabulary* voc) {
	for (int i = 0; i < voc->countwords; i++) {
		UpdateVocabularyPalindroms(voc, voc->words[i].word);
	}
	qsort(voc->palindroms, voc->countpalindroms, sizeof(WordInfo), WordInfoCompareByWordAsc);
	for (int i = 0; i < voc->countpalindroms; i++) {
		printf("%s\n", voc->palindroms[i].word);
	}
}


int main()
{
	FILE *file;
	if (fopen_s(&file, "C:\\Users\\micha\\source\\repos\\Lab4\\Input.txt", "r")) {
		exit(1);
	}
	setlocale(LC_ALL, "Russian");
	char* word, * context = NULL, line[LONG_STR], palindromline[LONG_STR];
	char separators[] = " ,.?!;:";


	Vocabulary voc;
	InitializeVocabulary(&voc);
	while (fgets(line, LONG_STR, file) != NULL) {
		palindromline[0] = '\0';
		_strlwr_s(line);
		if (line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = '\0';
		}
		
		word = strtok_s(line, separators, &context);
		while (word) {
			strcat_s(palindromline, word);
			UpdateVocabularyWords(&voc, word);
			word = strtok_s(NULL, separators, &context);

		}
		UpdateVocabularyPalindroms(&voc, palindromline);

	}
	fclose(file);
	
	UpdateAndPrintPalindroms(&voc);
	FreeVocabulary(&voc);

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

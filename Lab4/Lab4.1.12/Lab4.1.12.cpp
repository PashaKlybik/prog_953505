// Lab4.1.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#define LONG_STR 80

struct WordInfo {
	char* word;
	int repeats;
};

struct Vocabulary {
	int countwords;
	WordInfo* words;	
};

void InitializeVocabulary(Vocabulary* voc) {
	voc->countwords = 0;
	voc->words = NULL;
}

int WordInfoCompareByRepeatsDesc(const void* wordinfo1, const void* wordinfo2) {
	return ((WordInfo*)wordinfo2)->repeats - ((WordInfo*)wordinfo1)->repeats;
}

int WordInfoCompareByWordAsc(const void* wordinfo1, const void* wordinfo2) {
	return strcmp(((WordInfo*)wordinfo1)->word, ((WordInfo*)wordinfo2)->word);
}

void SortAndPrintVocabulary(Vocabulary* voc) {
	qsort(voc->words, voc->countwords, sizeof(WordInfo), WordInfoCompareByWordAsc);
	for (int i = 0; i < voc->countwords; i++) {
		printf("%s\t%d times\n", voc->words[i].word, voc->words[i].repeats);
	}
}

void FreeVocabulary(Vocabulary* voc) {
	for (int i = 0; i < voc->countwords; i++) {
		free(voc->words[i].word);
	}
	free(voc->words);
	InitializeVocabulary(voc);
}


void UpdateVocabularyWords(Vocabulary* voc, const char* word) {
	for (int i = 0; i < voc->countwords; i++) {
		if (!strcmp(word, voc->words[i].word)) {
			voc->words[i].repeats++;
			return;
		}
	}
	WordInfo wordinfo;
	wordinfo.word = _strdup(word);

	wordinfo.repeats = 1;
	voc->countwords++;
	voc->words = (WordInfo*)realloc(voc->words, voc->countwords * sizeof(WordInfo));
	voc->words[voc->countwords - 1] = wordinfo;

}



int main()
{
	char *word, *context=NULL, line[LONG_STR];
	char separators[] = " ,.?!;:";
	Vocabulary voc;
	InitializeVocabulary(&voc);
	gets_s(line, LONG_STR);
	word = strtok_s(line, separators,&context);
	while (word) {
		UpdateVocabularyWords(&voc, word);
		word = strtok_s(NULL, separators,&context);
		
	}

	SortAndPrintVocabulary(&voc);
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

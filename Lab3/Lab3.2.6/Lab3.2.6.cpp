// Lab3.2.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#define HOR_DIR 0
#define VERT_DIR 1



int RandomIndex(int a, int b) {
	float k = (float)rand()/(float)(RAND_MAX+1);
	return a + k*(b-a);
}

int GetFieldValue(int* field, int n, int i, int j) {
	return field[i*n+j];
}

void SetFieldValue(int* field, int n, int i, int j, int value) {
	field[i * n + j] = value;
}

int IsFieldAccepted(int* field, int n, int i, int j) {
	for (int i1 = i - 1; i1 < i + 2; i1++) {
		for (int j1 = j - 1; j1 < j + 2; j1++) {
			if (i1 > -1 && i1<n && j1>-1 && j1 < n) {
				if (GetFieldValue(field, n, i1, j1) > 0) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int TrySetTheShip(int* field, int n, int size) {
	int direction = RandomIndex(0, 2);

	int imax = n - (direction==HOR_DIR? 0: size - 1);
	int jmax = n - (direction==VERT_DIR? 0: size - 1);

	int i = RandomIndex(0, imax);
	int j = RandomIndex(0, jmax);
	
	for (int k = 0; k < size; k++) {
		int i1 = i + (direction == HOR_DIR ? 0 : k);
		int j1 = j + (direction == VERT_DIR ? 0 : k);
		if (IsFieldAccepted(field, n, i1, j1) == 0) 
		{
			return 0;
		}
	}
	for (int k = 0; k < size; k++) {
		int i1 = i + (direction == HOR_DIR ? 0 : k);
		int j1 = j + (direction == VERT_DIR ? 0 : k);
		SetFieldValue(field, n, i1, j1, size);
	}
	return 1;
}


void SetShips(const int n, int* field) {

	int sizes[] = { 4,3,3,2,2,2,1,1,1,1 };
	for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
	{
		while (!TrySetTheShip(field, n, sizes[i]));
	}
}

int main()
{
	srand(time(0));
	const int n = 10;

	int field[n * n];

	for (int i = 0; i < n * n; i++)
	{
		field[i] = 0;
	}

	SetShips(n, field);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", field[i * n + j]);
		}
		printf("\n");
	}


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

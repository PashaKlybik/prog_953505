// Lab2.2.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

float Factorial(int n) {
	while (n > 1) {
		return n * Factorial(n - 1);
	}
	return 1;
}

float RecurseDecomposition(float x, int n) {
	while (n > 0) {
		return (powf(-1.0, n) * powf(x, 2 * n + 1) / Factorial(2 * n + 1)) + RecurseDecomposition(x, n - 1);
	}
	return x;
}

int main()
{
	float x, eps, s, rd;
	int i = 0;
	char ch;
	do {
		printf_s("Enter the argument: ");
		scanf_s("%f", &x);

		s = sin(x);
		rd = RecurseDecomposition(x, i);

		printf_s("Enter the infelicity: ");
		scanf_s("%f", &eps);

		while (abs(s - rd) > eps) {
			rd = RecurseDecomposition(x, i);
			printf_s("%d\t%f\t%f\n", i + 1, s, rd);
			i++;
		}

		printf_s("%d parts needed\n", i);
		printf_s("Press [y] to repeat.");
		scanf_s("%c%c", &ch, 1, &ch, 1);
	} while (ch == 'y');
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

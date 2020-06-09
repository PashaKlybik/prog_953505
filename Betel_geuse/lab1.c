#include <stdio.h>//var2
void main()
{
	int j = 1, k, m;
	char b[65];
	unsigned long long d = 0, v;
	printf("Enter number: ");
	scanf_s("%d", &m);
	for (;; j = 1 - j)
	{
		d <<= 1, d |= j, d <<= 1, d |= j, d <<= 1, d |= j;
		if (d > m)
			break;

		v = d;
		for (k = 0; v;)

			b[k++] = (v & 1) + 48, v >>= 1; b[k--] = 0;

		printf("%d ", d);
		for (; k >= 0;)

			printf("%c", b[k--]);

		printf("\n");
	}
	return;
}
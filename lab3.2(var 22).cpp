#include <iostream>
int i;
void RashBereg(int* s, int* h, int* v);
void RashVoda(int* s, int* h, int* v);
int main()
{
	printf("\nEnter i=");
	scanf_s("%d", &i);
	int* h = new int[i];
	int* v = new int[i];
	int* s = new int[i];
	for (int t = 0; t < i; t++)
	{
		printf("\ns");
		printf("%d", t);
		printf("=");
		scanf_s("%d", &s[t]);
	}
	for (int t = 0; t < i; t++)
	{
		printf("\nh");
		printf("%d", t);
		printf("=");
		scanf_s("%d", &h[t]);
	}
	for (int t = 0; t < i; t++)
	{
		printf("\nv");
		printf("%d", t);
		printf("=");
		scanf_s("%d", &v[t]);
	}
	printf("\n1-Start Bereg");
	printf("\n2-Start Voda");
	printf("\nEnter Number=");
	int Number;
	k1:
	scanf_s("%d", &Number);
	switch (Number)
	{
	case 1: RashBereg(s, h, v); break;
	case 2: RashVoda(s, h, v); break;
	default: goto k1;
	}
	return 0;
}
void RashBereg(int *s,int *h,int *v)
{
	int n;
	double Sp=0;
	printf("Enter N s=");
	scanf_s("%d", &n);
	double* S = new double[n];
	S[0] = ((s[0] * h[0]) / 2.0)*v[0];
	for (int t = 1; t < n; t++)
	{
			S[t] = (((h[t - 1] + h[t]) / 2) * (s[t] - s[t - 1]))*v[t];
			Sp += S[t];
	}
	Sp += S[0];
	printf("KuboM/s=");
	printf("%f", Sp);
}
void RashVoda(int* s, int* h, int* v)
{
	int n1, n2;
	double Sp = 0;
	printf("Enter N s1=");
	scanf_s("%d", &n1);
	printf("Enter N s2=");
	scanf_s("%d", &n2);
	if (n1 > n2)
	{
		double* S = new double[n1 - n2];
		for (int i = n2;i<=n1;i++)
		{
			S[i-n2] = ((h[i] + h[i - 1]) / 2) * (s[i] - s[i-1]) * v[i-1];
			Sp += S[i - n2];
		}
	}
	else
	{
		double* S = new double[n2 - n1];
		for (int i = n1; i <= n2; i++)
		{
			S[i - n1] = ((h[i] + h[i - 1]) / 2) * (s[i] - s[i - 1]) * v[i - 1];
			Sp += S[i - n1];
		}
	}
	printf("KuboM/s=");
	printf("%f", Sp);
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int Random(int* k, int n);

int main()
{
    int  StructN = 0,n,n1,povt;
    StructN++;
    printf("Enter n=");
    scanf_s("%d", &n);
    int* k = new int[n];
    int* k1 = new int[n];
    *k = Random(k, n);
    for (int i = 0; i < n; i++)
    {
        k1[i] = k[i];
    }
    n1 = n;
    for (int q = 0; q < n1 - 1; q++)
    {
        povt = 0;
        for (int i = q + 1; i < n1; i++)
        {
            if (k1[q] == k1[i])
            {
                povt++;
                int t = i;
                for ( t; t < n1 - 1; t++)
                {
                    k1[t] = k1[t + 1];
                }
                n1--;
            }
        }
        if (povt > 0)
        {
            float k = ((float)(povt + 1) / n);
            float pr = (k * 100);
            printf("\n");
            printf("%d", k1[q]);
            printf("\n");
            printf("%f", pr);
            printf("%%");
        }
    }
    printf("\nBefore\n");
    for (int i = 0; i < n; i++)
    { 
        printf(" % d", k[i]);
        printf("\t");
    }
    printf("\nAfter\n");
    for (int i = 0; i < n1; i++)
    {
        printf("%d", k1[i]);
        printf("\t");
    }
    return 0;
}
int Random(int* k,int n)
{
    for (int i = 0; i < n; i++)
    {
        k[i] = rand() %10 + 1;
    }
    return *k;
}
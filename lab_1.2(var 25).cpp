// c_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

bool diag(int k, int l, int m, int n);

int main()
{
    int k=0, l=0, m=0, n=0; // k,l,m,n=(1...8)
    bool z = 0;
    l1:
    printf("k=");
    scanf_s("%d",&k);
    if (k < 1 || k>8)
    {
        printf_s("ERROR ONLY(1-8)");
        goto l1;
    }
    l2:
    printf("l=");
    scanf_s("%d", &l);
    if (l < 1 || l>8)
    {
        printf_s("ERROR ONLY(1-8)");
        goto l2;
    }
    l3:
    printf("m=");
    scanf_s("%d", &m);
    if (m < 1 || m > 8)
    {
        printf("ERROR ONLY(1-8)");
        goto l3;
    }
    l4:
    printf("n=");
    scanf_s ("%d", &n);
    if (n < 1 || n>8)
    {
        printf("ERROR ONLY(1-8)");
        goto l4;
    }
    if (m == k || n == l)
    {
        z++;
    }
    if (m == l || n == k)
    {
        z++;
    }
    z=diag(k, l, m, n);
    if (z==1)
        printf("threaten");
    else
        printf("not threaten");
    return 0;
}

bool diag(int k, int l, int m, int n)
{
    bool z = 0;
    for (int i = 1; i <= 8; i++)
    {
        if (n == l - i && m == k - i)
        {
            z++;
            return z;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if (n == l + i && m == k + i)
        {
            z++;
            return z;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if (n == l - i && m == k + i)
        {
            z++;
            return z;
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if (n == l + i && m == k - i)
        {
            z++;
            return z;
        }
    }
    return z;
}


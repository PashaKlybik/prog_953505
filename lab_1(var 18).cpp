#include <iostream>
#include "math.h"
using namespace std;

int kolvo(int k);

int main()
{
    int k, l,desk=0,desl=0;
    printf("k=");
    scanf_s("%d", &k);
    printf("l=");
    scanf_s("%d", &l);
    desk = kolvo(k);
    desl = kolvo(l);
    if (desk > desl)
    {
        for (int i = 10; i > 0; i--)
            printf(" ");
        printf("%d",k);
        printf("\n");
        for (int i = 10+(desk-desl); i > 0; i--)
            printf(" ");
        printf("%d", l);
        printf("\n");
        for (int i = 20; i > 0; i--)
            printf("-");
        printf("\n");
        int q = l,z=9,j;
        do
        {
            z--;
            j = z;
            int x;
            x = k * (q % 10);
            for (j; j > 0; j--)
                printf(" ");
            printf("+ ");
            printf("%d", x);
            printf("\n");
            q = q / 10;
        } while (q > 0);
        for (int i = 20; i > 0; i--)
            printf("-");
        printf("\n");
        desl = kolvo(l * k);
        for (int i = 10-(desl-desk); i > 0; i--)
            printf(" ");
        printf("%d", (l * k));
    }
    else
    {
        for (int i = 10; i > 0; i--)
            printf(" ");
        printf("%d", l);
        printf("\n");
        for (int i = 10 + (desk - desl); i > 0; i--)
            printf(" ");
        printf("%d", k);
        printf("\n");
        for (int i = 20; i > 0; i--)
            printf("-");
        printf("\n");
        int q = l, z = 9, j;
        do
        {
            z--;
            j = z;
            int x;
            x = k * (q % 10);
            for (j; j > 0; j--)
                printf(" ");
            printf("+ ");
            printf("%d", x);
            printf("\n");
            q = q / 10;
        } while (q > 0);
        for (int i = 20; i > 0; i--)
            printf("-");
        printf("\n");
        desl = kolvo(l * k);
        for (int i = 10 - (desl - desk); i > 0; i--)
            printf(" ");
        printf("%d", (l * k));
    }
}
int kolvo(int k)
{
    int digit,N=0;
    digit = k;
    while (digit > 0)
    {
        digit =digit / 10;
        N++;
    }
    return N;
}

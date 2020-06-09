#include <conio.h>
#include <iostream>
#include <math.h>

int main()
{
    const double pi = 3.1415926535;
    int n=1;
    double F=0, N=0;;
    printf("\nEnter e=");
    float e;
    scanf_s("%F", &e);
    while ((pi-F)>e)
    {
        N += 1 / pow(n, 2);
        F = sqrt(6 * N);
        n++;
    }
    printf("\nn=");
    printf("%d", n);
}

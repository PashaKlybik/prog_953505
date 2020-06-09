#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int kolvo(char* N);
int kolvonumb(int N);
int InNum(char* Number, int k);
int main()
{
    int n,kolvo1,kolvo2,St;
    long int Sum = 0;
    printf("Enter length=");
    scanf_s("%d", &n);
    char* Number1 = new char[n];
    char* Number2 = new char[n];
    printf("\nNumber1=");
    gets_s(Number1, n+1);
    gets_s(Number1, n+1);
    printf("\nNumber2=");
    gets_s(Number2, n+1);
    kolvo1 = kolvo(Number1);
    kolvo2 = kolvo(Number2);
    Sum = InNum(Number1, kolvo1) + InNum(Number2, kolvo2);
    int kolvS = kolvonumb(Sum);
    char* Summ = new char[kolvS];
    St = kolvonumb(Sum)-1;
    for (int i = 0; i <kolvS; i++)
    {

        Summ[i] = (Sum / pow(10, St)) + '0';
        Sum = Sum % (int)pow(10, St);
        St--;
        if (St < 0) break;
    }
    printf("\nSumm=");
    for (int i = 0; i < kolvS; i++)
    {
        printf("%c", Summ[i]);
    }
}
int kolvo(char* N)
{
    int i = 0;
    while (*N++)
    {
        i++;
    }
    return i;
}
int kolvonumb(int N)
{
    int i=0;
    while (N)
    {
        N /= 10;
        i++;
    }
    return i;
}
int InNum(char* Number,int k)
{
    int Num=0,St=0;
    for (int i = k - 1; i >= 0; i--)
    {

        Num += pow(10, St) * (Number[i] - '0');
        St++;
    }
    return Num;
}
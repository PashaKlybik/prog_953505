#include <stdio.h>
#include <math.h>
#include <limits.h>

int len1(int x)
{
    int d = 0;
    if (x == 0)
        return 1;
    while (x > 0)
    {
        x /= 10;
        d++;
    }
    return d;
}

void spaces1(int x)
{
    int i = 0;
    for (i = 0; i < x; i++)
        printf(" ");
}

void tire1(int x)
{
    int i = 0;
    for (i = 0; i < x; i++)
        printf("-");
}

int max1(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int version1()
{
    int x, y, dx, dy, ans, da, i;
    printf("Vvedite dva natural'nih chisla\n");
    scanf("%d %d", &x, &y);
    if (x <= 0 || y <= 0)
    {
        printf("\nNe vnaturi");
        return 0;
    }
    if (x > INT_MAX / y || y > INT_MAX / x)
    {
        printf("\nPerestaralsya malex");
        return 0;
    }
    ans = x * y;
    dx = len1(x);
    spaces1(20 - dx);
    printf("%d\n", x);
    dy = len1(y);
    spaces1(20 - max1(dx, dy) - 1);
    printf("x\n");
    spaces1(20 - dy);
    printf("%d\n", y);
    da = len1(ans);
    spaces1(20 - da - dy + 1);
    tire1(da + dy - 1);
    printf("\n");
    i = 0;
    while (1)
    {
        int v = y % 10, d = len1(v * x);
        spaces1(20 - d - i);
        printf("%d", v * x);
        spaces1(i);
        printf("\n");
        if (y / 10 == 0)
        {
            spaces1(20 - da - i);
            tire1(da + i);
            printf("\n");
            break;
        }
        /*
        else
        {                    //Mozhno ubrat'
        spaces (20-d-i-2);
        printf ("+\n");
        }
        */
        y /= 10;
        i++;
    }
    spaces1(20 - da);
    printf("%d\n", ans);

    return 0;
}

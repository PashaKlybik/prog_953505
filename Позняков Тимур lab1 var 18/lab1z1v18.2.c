#include <stdio.h>
#include <math.h>
#include <limits.h>

int len(int x)
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

void spaces(int x)
{
    int i = 0;
    for (i = 0; i < x; i++)
        printf(" ");
}

void tire(int x)
{
    int i = 0;
    for (i = 0; i < x; i++)
        printf("-");
    printf("\n");
}

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int version2()
{
    int x, y, dx, dy, ans, da, i, pr, st;
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
    dx = len(x);
    spaces(20 - dx);
    printf("%d\n", x);
    dy = len(y);
    spaces(20 - max(dx, dy) - 1);
    printf("x\n");
    spaces(20 - dy);
    printf("%d\n", y);
    da = len(ans);
    spaces(20 - da - dy + 1);
    tire(da + dy - 1);
    i = 0;
    pr = -1;
    st = 1;
    while (1)
    {
        int v = y % 10, d = len(v * x);
        spaces(20 - d - i);
        printf("%d", v * x);
        spaces(i);
        printf("\n");

        if (pr == -1)
        {
            pr = v * x;
            spaces(20 - d - i - 2);
            printf("+\n");
        }
        else
        {
            int dp;
            spaces(20 - da - dy + 1);
            tire(da + dy - 1);
            st *= 10;
            pr += v * x * st;
            dp = len(pr);
            spaces(20 - dp);
            printf("%d\n", pr);
            if (y / 10 == 0)
                break;
            spaces(20 - dp - 2);
            printf("+\n");
        }
        y /= 10;
        i++;
    }

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include<conio.h>
int main()
{
    bool isRepeat = false;
    int countOfMatrixes, columns, rows;
    printf("Enter count of matrixes: ");
    scanf_s("%d", &countOfMatrixes);
    printf("Enter count of rows: ");
    scanf_s("%d", &rows);
    printf("Enter count of symbols in row: ");
    scanf_s("%d", &columns);

    char*** matrix = (char***)malloc(sizeof(char) * countOfMatrixes);
    for (int l = 0;l < countOfMatrixes;l++)
    {
        matrix[l] = (char**)malloc(sizeof(char) * rows);
    }

    for (int l = 0;l < countOfMatrixes;l++)
    {
        for (int i = 0;i < rows;i++)
        {
            matrix[l][i] = (char*)malloc(sizeof(char) * columns);
        }
    }

    for (int l = 0;l < countOfMatrixes;l++)
    {
        for (int i = 0;i < rows;i++)
        {
            
            for (int j = 0;j < columns;j++)
            {
                char ch = _getch();
                matrix[l][i][j] = ch;
            }
        }
    }

    for (int l = 0;l < countOfMatrixes;l++)
    {
        for (int i = 0; i < rows;i++)
        {
            isRepeat = false;
            for (int j = 0; j < columns; j++)
            {
                for (int k = 1;k < columns; k++)
                {
                    if (matrix[l][i][j] == matrix[l][i][k])
                    {
                        isRepeat = true;
                        for (int m = 0;m < columns;m++)
                        {
                            if (matrix[l][i][m] >= 97 && matrix[l][i][m] <= 122)continue;
                            if (matrix[l][i][m] >= 65 && matrix[l][i][m] <= 90);
                            {
                                matrix[l][i][m] += 32;
                            }
                        }
                        break;
                    }
                }

                if (isRepeat == false)
                {
                    for (int m = 0;m < columns;m++)
                    {
                        if (matrix[l][i][m] >= 97 && matrix[l][i][m] <= 122)
                        {
                            matrix[l][i][m] -= 32;
                        }
                    }
                }
                break;
            }
        }
    }

    for (int l = 0;l < countOfMatrixes;l++)
    {
        printf("Matrix %d: \n", (l + 1));
        for (int i = 0;i < rows;i++)
        {
            for (int j = 0;j < columns;j++)
            {
                printf("%c", matrix[l][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

}
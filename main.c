#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define SIZE 10

int main()
{
    int mat[SIZE][SIZE];
    int line, col;
    char x;
    do
    {
        scanf("%c", &x);
        if (x == 'A')
        {
            createMat(mat);
        }
        if (x == 'B')
        {
            scanf("%d", &line);
            scanf("%d", &col);
            if (ifExistRoute(line, col, mat) == 1)
                printf("True \n");
            else
                printf("False \n");
        }
        if (x == 'C')
        {
            scanf("%d", &line);
            scanf("%d", &col);
            printf("%d \n", bringTheShortestRoute(line, col, mat));
        }

    } while (x!='D');
    printf("Program is over \n");
    return 0;
}
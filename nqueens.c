#include <stdio.h>
#include <stdlib.h>
int board[20], count = 0;
// Function to print the solution
void printSolution(int n)
{
    int i, j;
    printf("\nSolution %d:\n", ++count);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}
// Function to check if a queen can be placed in the given row and column
int isSafe(int row, int col)
{
    for (int i = 1; i <= row - 1; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return 0;
        }
    }
    return 1;
}
// Function to solve the n-queens problem using backtracking
void nQueens(int row, int n)
{
    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                printSolution(n);
            }
            else
            {
                nQueens(row + 1, n);
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(1, n);
}
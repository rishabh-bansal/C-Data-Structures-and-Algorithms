#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int binarysearch(int, int[], int);

/*  Longest Increasing Subsequence in an integer array
    Input: Length of array and array itself
    Output: Length of Longest Increasing Subsequence
*/

int LIS(int N, int *keyarr)
{
        int size = 0, i;
        int*A = (int*)malloc(N * sizeof(int));
        for ( i = 0; i < N; i++)
        {
                int j = binarysearch(keyarr[i], A, size);
                A[j] = keyarr[i];
                if (j == size)
                {
                        size++;
                }
        }
        return size;
}

/* Helper Function */

int binarysearch(int k, int A[], int size)
{
        int low = 0;
        int high = size - 1;
        while (low <= high)
        {
                int mid = (low + high) / 2;
                if (k < A[mid])
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        return low;
}

/*  Longest Common Subsequence between two strings
	Input: Two Strings
	Output: Length and the Longest Common Subsequence
*/ 

void LCSS(char *X, char *Y)
{
        int i, j, k, r, c, m, n, l, z;
        m = strlen(X);
        n = strlen(Y);
        int **LCS = (int**)malloc((m + 1) * sizeof(int*));
        for ( i = 0; i < m + 1; i++)
        {
                LCS[i] = (int*)malloc((n + 1)* sizeof(int));
        }
        for (i = 0; i < m + 1; i++)
        {
                LCS[i][n] = 0;
        }
        for ( j = 0; j < n + 1; j++)
        {
                LCS[m][j] = 0;
        }
        for ( c = n - 1; c >= 0; c--)
        {
                for ( r = m - 1; r >= 0; r--)
                {
                        if (X[r] == Y[c])
                        {
                                LCS[r][c] = 1 + LCS[r + 1][c + 1];
                        }
                        else
                        {
                                LCS[r][c] = LCS[r + 1][c] > LCS[r][c + 1] ? LCS[r + 1][c] : LCS[r][c + 1];
                        }
                }
        }
        printf("%d\n", LCS[0][0]);
        z = LCS[0][0];
        l = 0, k = 0;
        while (LCS[k][l] != 0)
        {
                if (LCS[k][l] == 1 + LCS[k + 1][l + 1] && LCS[k][l] != LCS[k][l + 1] && LCS[k][l] != LCS[k + 1][l])
                {
                        printf("%c",X[k]);
                        k++;
                        l++;
                }
                else if (LCS[k][l] == LCS[k + 1][l])
                        k++;
                else if (LCS[k][l] == LCS[k][l + 1])
                        l++;
        }
        printf("\n");
}

/*  Longest Common Subword between two strings
	Input: Two Strings
	Output: Length and the Longest Common Subword
*/ 

void LCSW(char *X, char *Y)
{
		int i, j, k, z, m, n, r, c, x, y, p;
		m = strlen(X);
        n = strlen(Y);
        int **LCW = (int**)malloc((m + 1) * sizeof(int*));
        for (i = 0; i < m + 1; i++)
        {
                LCW[i] = (int*)malloc((n + 1) * sizeof(int));
        }
        for (i = 0; i < n + 1; i++)
        {
                LCW[m][i] = 0;
        }
        for (i = 0; i < m + 1; i++)
        {
                LCW[i][n] = 0;
        }
        z = 0;
        for (c = n - 1; c >= 0; c--)
        {
                for (r = m - 1; r >= 0; r--)
                {
                        if (X[r] == Y[c])
                        {
                                LCW[r][c] = LCW[r + 1][c + 1] + 1;
                        }
                        else
                                LCW[r][c] = 0;
                        if (z < LCW[r][c])
                        {
							z = LCW[r][c];
                        }
                }
        }
        printf("%d\n", z);
        p = 0;
        for (r = 0; r < m; r++)
        {
                for (c = 0; c < n; c++)
                {
                        if (LCW[r][c] == z)
                        {
                                x = r;
                                y = c;
                                p = 1;
                                break;
                        }
                }
                if (p == 1)
                        break;
        }
        while (LCW[x][y] != 0)
        {
                printf("%c",X[x]);
                x++;
                y++;
        }
        printf("\n");
}

/*  Solution to the popular Knapsack Problem
	Input: N and total weight capacity
	Output: Maximum value possible
*/

int knapsack(int N, int w)
{
        int *W, *V, i, x;
        W = (int*)malloc((N + 1) * sizeof(int));
        V = (int*)malloc((N + 1) * sizeof(int));
        int **A = (int**)malloc((N+1) * sizeof(int*));
        printf("Enter Weight\n");
        for (i = 1; i < N + 1; i++)
        {
                 scanf("%d",&W[i]);
        }
        printf("Enter Values\n");
        for (i = 1; i < N + 1; i++)
        {
                scanf("%d",&V[i]);
        }
        for (i = 0; i < N + 1; i++)
        {
                A[i] = (int*)malloc((w+1)*sizeof(int));
        }
        for (i = 0; i < w + 1; i++)
        {
                A[0][i] = 0;
        }
       for (i = 1; i < N + 1; i++)
        {
                for (x = 0; x < w + 1; x++)
                {
                        if (x < W[i])
                        {
                                A[i][x] = A[i - 1][x];
                        }
                        else
                        {
                                A[i][x] = A[i - 1][x] > A[i-1][x - W[i]] + V[i] ? A[i-1][x]:(A[i-1][x - W[i]] + V[i]);
                        }
                }
        }
        return A[N][w];
}                                                                                                                               
         
         
         
         
         
         
         
                                          

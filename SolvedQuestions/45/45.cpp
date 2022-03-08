// Kth element in Matrix
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    int r;
    cin >> r;
    cout << kthSmallest(mat, n, r) << endl;

    return 0;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int x = 0, y = 0, smallInd[2];
    smallInd[0] = n;
    smallInd[1] = n;
    for (int i = 0; i < k; i++)
    {
        if(mat[x][y + 1] > mat[x + 1][y]){
            if(mat[x+1][y]<mat[smallInd[0]][smallInd[1]]){
                
            }
            smallInd[0] = x;
            smallInd[1] = y + 1;
            x = x + 1;
        }else{
            smallInd[0] = x + 1;
            smallInd[1] = y;
            y = y + 1;
        }
        
    }
}

// Optimal Solution -

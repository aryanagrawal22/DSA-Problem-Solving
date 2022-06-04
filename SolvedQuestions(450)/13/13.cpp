// Kadane's Algorithm
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Solution: https://www.youtube.com/watch?v=HCL4_bOd3-4

#include <bits/stdc++.h>
using namespace std;

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int maxSubarraySum(int arr[], int n)
{
    int curSum = 0;
    int maxSum = 0;

    for (int i = 0; i <= n; i++)
    {

        curSum = curSum + arr[i];

        if (curSum > maxSum)
        {
            maxSum = curSum;
        }

        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    if (maxSum == 0)
    {
        maxSum = -9999;
        for (int j = 0; j<=n; j++)
        {
            if (arr[j] > maxSum)
            {
                maxSum = arr[j];
            }
        }
    }

    return maxSum;
}

int main()
{
    int arr[] = {-1, -2, -3, -4};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxSubarraySum(arr, n - 1);

    return 0;
}

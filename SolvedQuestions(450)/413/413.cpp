#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of arr
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        int maxSoFar = -99999, maxHere = 0;
        for (int i =0; i<n; i++){
            if (arr[i]+maxHere > maxSoFar){
                maxSoFar = arr[i]+maxHere;
                if(maxHere+arr[i]>0){
                    maxHere = maxHere + arr[i];
                }else{
                    maxHere = 0;
                }
            }else{
                if(maxHere+arr[i]>0){
                    maxHere = maxHere + arr[i];
                }else{
                    maxHere = 0;
                }
            }
        }
        return maxSoFar;
    }
};


int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    Solution ob;

    cout << ob.maxSubarraySum(a, n) << endl;
}
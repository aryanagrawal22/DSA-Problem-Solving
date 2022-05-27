// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {

        // Traverse N and save each to a Map
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            um[arr[i]]++;
        }

        int count = 0;

        // Traverse map -> if less than k then find k-arr[i] element in map
        for (auto x : um)
        {
            int num1 = x.first;
            if (num1 < k)
            {
                int num2 = k - num1;
                if (num1 == num2)
                {
                    /* {1, 1, 1, 1}
                        num1 = 1;
                        val1 = 1;
                        num2 = 1;
                        val2 = 3;

                        1*3+ 1*3+ 1*3+ 1*3 = (1*3)*4

                        {1, 1, 1}
                        num1 = 1;
                        val1 = 1;
                        num2 = 1;
                        val2 = 2;

                        1*2 + 1*2 + 1*2 = (1*2)*3
                    */

                    int val2 = (um[num2] - 1)*(um[num2]);
                    count += val2;
                }
                else
                {
                    int val2 = um[num2];
                    int val1 = x.second;
                    count += val1 * val2;
                }
            }
            
        }

        return count / 2;
    }
};

// { Driver Code Starts.

int main()
{
    int arr[] = {1, 5, 5, 5, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
    return 0;
} 

/*1, 2, 3
  1, 3, 1

  
*/
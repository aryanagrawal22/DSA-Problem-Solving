#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int minJumps(int arr[], int n)
    {
        if(n<=1){
            return 0;
        }

        if(arr[0]==0){
            return -1;
        }

        int steps = arr[0];
        int maxReach = arr[0];
        int jumps = 1;

        for(int i = 1; i<n; i++){
            if(i==n-1){
                return jumps;
            }

            maxReach = max(maxReach, i + arr[i]);

            steps--;
            if(steps==0){
                jumps++;
                if(i>=maxReach){
                    return -1;
                }
                steps = maxReach - 1;
            }

        }
        return -1;
    }
};

int main()
{
    int arr[] = {1, 4, 3, 2, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout << obj.minJumps(arr, n) << endl;
    return 0;
}
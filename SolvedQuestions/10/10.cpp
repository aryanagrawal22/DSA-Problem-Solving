#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int maxFinder(int arr[], int maxJump, int currIndex){
        int max = -99999;
        int ind ;
        for (int i =currIndex+1; i<maxJump; i++){
            if (arr[i]>=max){
                max = arr[i];
                ind = i;
            }
        }
        return ind;
    }

    int minJumps(int arr[], int n)
    {
        int count = 0;
        for  (int i = 0; i< n; i++){
            
            if(arr[i]==0) {
                count=-1;
                break;
            }
            
            int jump = maxFinder(arr, arr[i], i);
            i = i + jump - 1;
            // cout<<i+1;
            
            count++;

            if(i>=n-2){ break;}

        }
    
        return count;
    }
};

int main()
{
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout << obj.minJumps(arr, n) << endl;
    return 0;
}
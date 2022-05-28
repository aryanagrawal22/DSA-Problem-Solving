#include<bits/stdc++.h>

using namespace std;

class Solution{

    public:
    long long trappingWater(int arr[], int n){

        //Left Max calculated
        int Max = -9999999, left[n];
        for (int i = 0; i<n; i++){
            Max = max(Max, arr[i]);
            left[i] = Max;
        }
        
        //Right Max calculated
        Max = -9999999;
        int right[n];
        for (int i = n-1; i>=0; i--){
            Max = max(Max, arr[i]);
            right[i] = Max;
        }

        //Calculate WaterBlock 
        int waterBlock = 0;
        for (int i = 0; i<n; i++){
            int rightMax = arr[i];
            int leftMax = arr[i];
            waterBlock += min(right[i], left[i]) - arr[i];
        }

        return waterBlock;
    }
};


int main(){
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout << obj.trappingWater(arr, n) << endl;    
    return 0;
}
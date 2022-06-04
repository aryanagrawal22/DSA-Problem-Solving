#include <bits/stdc++.h>
using namespace std;

int profit(int arr[], int len){
    
    int profit = 0, buy = 99999, sell = 0;
    for (int i = 0; i<len; i++){
        if(arr[i]<buy){
            buy = arr[i];
        }

        if(arr[i]>sell){
            sell = arr[i];
        }

        int diff = sell - buy;
        
        if(diff>profit){
            profit = diff;
        }
    }

    return profit-1;
}

int main(){
    int arr [] = {7,1,5,3,6,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<profit(arr, n);
}
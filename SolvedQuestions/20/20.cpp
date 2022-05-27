#include<bits/stdc++.h>
using namespace std;

void reorderPosNeg(int arr[], int n)
{
    int i = 0, j = n-1;
 
    
    while (i < j) {
        while (i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j )
            swap(arr[i], arr[j]);
    }
 

    if (i == 0 || i == n)
        return;
 
    int k = 0;
    while (k < n && i < n ) {

        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

int main(){
    int arr [] = {-5, -2, 5, 2, 4, 7, 1, 8, -8};
    int n = sizeof(arr)/sizeof(arr[0]);
    reorderPosNeg(arr, n);
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
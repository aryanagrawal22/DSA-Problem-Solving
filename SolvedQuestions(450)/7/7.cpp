// Given an array, rotate the array by one position in clock-wise direction.


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 
// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}

void rotate(int arr[], int n)
{
    int temp1, temp2;
    for (int i=0; i<n; i++){
        if(i!=0 && i!=n-1){
            temp2 = arr[i+1];
            arr[i+1] = temp1;
            temp1 = temp2;
        }else if(i==0){
            temp1 = arr[i+1];
            arr[i+1] = arr[i];
        }else{
            arr[0] = temp1;
        }
    }
}

int main()
{
    int arr[]= {85, 25, 1, 32, 54, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    rotate(arr, n);
    printArray( arr, n );
 
    return 0;
}



// *** OPTIMAL WAY (Min Heap Approach)

// void rotate(int arr[], int n)
// {
//    int temp = arr[n-1];
//    for(int i = n-1; i>=0; i--){
//        arr[i] = arr[i-1];
//    }
//    arr[0] = temp;
// }
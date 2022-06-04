// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.


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


// Function that finds union of two arrays
void unionMaker(int arr1[], int arr2[], int size1, int size2)
{

    int arr [size1 + size2];

    for (int i = 0; i<size1; i++){
        arr[i]=arr1[i];
    }

    for (int j = size1; j < size1+size2; j++){
        arr[j]=arr2[j-size1];
    }

    sort(arr, arr+size1+size2);

    printArray(arr, size1+size2);

    int count = 0;

    for (int k = 0; k<size1+size2; k++){
        
        if (arr[k]!=arr[k+1]){
            count++;
        }
    }

    cout<<count;

}
 
// Driver Code
int main()
{
    int arr1[]= {85, 25, 1, 32, 54, 6}, arr2[] = {85, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    unionMaker(arr1, arr2, n, m);
 
    return 0;
}




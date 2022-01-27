// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order. Sort the array without using any sorting algo

#include <bits/stdc++.h>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void arrSort(int arr[], int size){
    vector<int> arr0, arr1, arr2, arrx;
    
    for(int i=0; i < size; i++){
        if(arr[i]==0){
            arr0.push_back(0);
        } 
        if(arr[i]==1){
            arr1.push_back(1);
        }
        if(arr[i]==2){
            arr2.push_back(2);
        } 
    }
    arr0.insert(arr0.end(), arr1.begin(), arr1.end());
    arr0.insert(arr0.end(), arr2.begin(), arr2.end());
    for(int i=0; i < arr0.size(); i++){
        cout << arr0.at(i) << ' ';
    }

}

/* Utility function to print an array  */
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}

/* Main Function */
int main()
{
    int n;
    cin>>n;
    int *arr = new int(n);
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }
    arrSort(arr, n);
    // printArray(arr, n);
    return 0;
}


// *** OPTIMAL WAY (Min Heap Approach)
// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// // C++ program to sort an array
// // with 0, 1 and 2 in a single pass
// #include <bits/stdc++.h>
// using namespace std;
 
// // Function to sort the input array,
// // the array is assumed
// // to have values in {0, 1, 2}
// void sort012(int a[], int arr_size)
// {
//     int lo = 0;
//     int hi = arr_size - 1;
//     int mid = 0;
 
//     // Iterate till all the elements
//     // are sorted
//     while (mid <= hi) {
//         switch (a[mid]) {
 
//         // If the element is 0
//         case 0:
//             swap(a[lo++], a[mid++]);
//             break;
 
//         // If the element is 1 .
//         case 1:
//             mid++;
//             break;
 
//         // If the element is 2
//         case 2:
//             swap(a[mid], a[hi--]);
//             break;
//         }
//     }
// }
 
// // Function to print array arr[]
// void printArray(int arr[], int arr_size)
// {
//     // Iterate and print every element
//     for (int i = 0; i < arr_size; i++)
//         cout << arr[i] << " ";
// }
 
// // Driver Code
// int main()
// {
//     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
//     int n = sizeof(arr) / sizeof(arr[0]);
 
//     sort012(arr, n);
 
//     cout << "array after segregation ";
 
//     printArray(arr, n);
 
//     return 0;
// }
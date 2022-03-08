// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers


#include <bits/stdc++.h>
using namespace std;
 
// Function that seperates the negative and positive numbers in an array
void seperator(int a[], int size)
{
    int lo = 0;
    int mid = 0;

    // Loop till mid is equal to array size
    while (mid <= size) {

        //if negative than swap to low and then low++ , mid++
        if(a[mid]<0){
            swap(a[lo++], a[mid++]);

        //else positive then let it be and only mid++
        }else{
            mid++;
        }
    }
}
 
// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}
 
// Driver Code
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);

    seperator(arr, n);
 
    cout << "array after segregation:\n";
 
    printArray(arr, n);
 
    return 0;
}
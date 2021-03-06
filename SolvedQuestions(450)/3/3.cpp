// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

#include <bits/stdc++.h>
using namespace std;

/* Function to find kth smallest term */
void ksmallest(int arr[], int length, int k)
{
    // Insertion Sort - stable sort ( For small array size )
    
    for (int i = 1; i < length; i++) {
    int key = arr[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
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
    int n, k;
    cin>>n;
    int *arr = new int(n);
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;
    ksmallest(arr, n, k);
    // printArray(arr, n);
    cout<<arr[k-1];
    return 0;
}


// *** OPTIMAL WAY (Min Heap Approach)
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/


// // A C++ program to find k'th smallest element using min heap
// #include <climits>
// #include <iostream>
// using namespace std;
 
// // Prototype of a utility function to swap two integers
// void swap(int* x, int* y);
 
// // A class for Min Heap
// class MinHeap {
//     int* harr; // pointer to array of elements in heap
//     int capacity; // maximum possible size of min heap
//     int heap_size; // Current number of elements in min heap
// public:
//     MinHeap(int a[], int size); // Constructor
//     void MinHeapify(int i); // To minheapify subtree rooted with index i
//     int parent(int i) { return (i - 1) / 2; }
//     int left(int i) { return (2 * i + 1); }
//     int right(int i) { return (2 * i + 2); }
 
//     int extractMin(); // extracts root (minimum) element
//     int getMin() { return harr[0]; } // Returns minimum
// };
 
// MinHeap::MinHeap(int a[], int size)
// {
//     heap_size = size;
//     harr = a; // store address of array
//     int i = (heap_size - 1) / 2;
//     while (i >= 0) {
//         MinHeapify(i);
//         i--;
//     }
// }
 
// // Method to remove minimum element (or root) from min heap
// int MinHeap::extractMin()
// {
//     if (heap_size == 0)
//         return INT_MAX;
 
//     // Store the minimum value.
//     int root = harr[0];
 
//     // If there are more than 1 items, move the last item to root
//     // and call heapify.
//     if (heap_size > 1) {
//         harr[0] = harr[heap_size - 1];
//         MinHeapify(0);
//     }
//     heap_size--;
 
//     return root;
// }
 
// // A recursive method to heapify a subtree with root at given index
// // This method assumes that the subtrees are already heapified
// void MinHeap::MinHeapify(int i)
// {
//     int l = left(i);
//     int r = right(i);
//     int smallest = i;
//     if (l < heap_size && harr[l] < harr[i])
//         smallest = l;
//     if (r < heap_size && harr[r] < harr[smallest])
//         smallest = r;
//     if (smallest != i) {
//         swap(&harr[i], &harr[smallest]);
//         MinHeapify(smallest);
//     }
// }
 
// // A utility function to swap two elements
// void swap(int* x, int* y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
 
// // Function to return k'th smallest element in a given array
// int kthSmallest(int arr[], int n, int k)
// {
//     // Build a heap of n elements: O(n) time
//     MinHeap mh(arr, n);
 
//     // Do extract min (k-1) times
//     for (int i = 0; i < k - 1; i++)
//         mh.extractMin();
 
//     // Return root
//     return mh.getMin();
// }
 
// // Driver program to test above methods
// int main()
// {
//     int arr[] = { 12, 3, 5, 7, 19 };
//     int n = sizeof(arr) / sizeof(arr[0]), k = 2;
//     cout << "K'th smallest element is " << kthSmallest(arr, n, k);
//     return 0;
// }
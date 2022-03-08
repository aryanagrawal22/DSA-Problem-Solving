// Next Permutation
// https://leetcode.com/problems/next-permutation/
// Reffered : https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation

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

void permutation(int arr[], int start, int n)
{
    int index;
    for (int i = n; i>=0; i--){

        if (arr[i-1]<arr[i]){
            index = i-1;
            break;
        }
    }
    
    for (int j = n; j>index; j--){
        if (arr[index]<arr[j]){
            swap(arr[index], arr[j]);
            break;
        }
    }

    index++;
    n++;
    reverse(arr + index, arr + n);

    printArray(arr, n);

}

int main()
{
    int arr[]= {0, 1, 2, 5, 3, 3, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    permutation(arr, 0, n-1);
    // printArray( arr, n );
 
    return 0;
}



// *** OPTIMAL WAY (Min Heap Approach)

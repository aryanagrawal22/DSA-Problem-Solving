// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
// Solution: https://www.youtube.com/watch?v=pavdSf5f5pw

// Other approaches thought of were Hash Table which did not follow the questions criteria of constant memory and Visited value to be made negative whoch did not follow the questions criteria of not modifying the array.

// Best approach is Linked List Loop approach ( By Slow and Fast )

#include <bits/stdc++.h>
using namespace std;

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

/* Here we make form a linked list and because there is a duplicate value it forms a cycle and thus we need to find the entry point of the cycle which can be found out using slow/fast meathod where:
1) Both Slow and Fast are set to the origin ie, 0 index of linked list (array)
2) Slow moves 1 step and fast moves 2 steps until they meet
3) After they meet fast is set to origin and then both move 1 step until they meet again
4) The place they meet is the answer or the entry point of loop thus the duplicate value
*/
int duplicateFinder(int nums[], int n)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << duplicateFinder(arr, n - 1);

    return 0;
}

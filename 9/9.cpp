// Minimize the Heights II
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Solution:

#include <bits/stdc++.h>
using namespace std;

// Solution object class
class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);
        int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

        int tempmin, tempmax;
        tempmin = arr[0];
        tempmax = arr[n - 1];

        for (int i = 1; i < n; i++)
        {
            tempmin = min(arr[0] + k, arr[i] - k);         // Minimum element when we add k to whole array
            
            tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we subtract k from whole array
            
            ans = min(ans, tempmax - tempmin);
        }
        return ans;
    }
};

// Main Function
int main()
{

    int n, k;
    cin >> k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.getMinDiff(arr, n, k);
    cout << ans << "\n";

    return 0;
}

// Failed Attempt

// #include <bits/stdc++.h>
// using namespace std;

// // Solution object class
// class Solution
// {
// public:

//     int getMinDiff(int arr[], int n, int k)
//     {

//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum = sum + arr[i];
//         }
//         int avg = sum / n;

//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] > avg)
//             {
//                 if(arr[j]-k<0){
//                     arr[j] = arr[j] + k;
//                 }else{
//                     arr[j] = arr[j] - k;
//                 }

//             }
//             else
//             {
//                 arr[j] = arr[j] + k;
//             }
//         }

//         int max = -9999;
//         int min = 9999;

//         for (int k = 0; k < n; k++)
//         {
//             if (arr[k] > max)
//             {
//                 max = arr[k];
//             }
//             if (arr[k] < min)
//             {
//                 min = arr[k];
//             }
//         }

//         return (max - min);
//     }
// };

// // Main Function
// int main()
// {

//     int n, k;
//     cin >> k;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     Solution ob;
//     auto ans = ob.getMinDiff(arr, n, k);
//     cout << ans << "\n";

//     return 0;
// }
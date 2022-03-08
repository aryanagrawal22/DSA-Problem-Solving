// Median in a row-wise sorted Matrix
// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){

        vector<int>ans;

        for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               ans.push_back(matrix[i][j]);
           }
       }
       
       sort(ans.begin(),ans.end());
       
       int size = ans.size();
       
       int mainans = ans[size/2];
       
       return mainans;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends



// Optimal Solution - Binary Search
// Link - https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

// int medianRowwiseSortedMatrix(int matrix[N][M])
// {
//     int min = INT_MAX;
//     int max = INT_MIN;
//     int desired_count = (1+(N*M)/2))
//    for(int i=0;i<N;i++)
//     {
//         if(A[i][0]<min)
//         min = A[i][0];
//         if(A[i][M-1]>max)
//         max = A[i][M-1];
//     }
//     int counter =0;
//     while(min<max)
//     {
//         counter=0;
//         int mid = (max+min)/2;
//         for(int i= 0;i<N;i++)
//         {
//             counter += upper_bound(A[i], A[i]+M, mid) -  A[i];
//         }
//         if(counter < desired_count)
//             min = mid+1;
//         else
//             max = mid;
//     }
//     return min;
// }
// Row with max 1s
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int max1 = 0, index;
	    for (int i = 0; i < n; i++){
            int row1 = 0;
            for(int j = 0; j < m; j++){
                if(arr[i][j]==1){
                    row1++;
                }
            }
            if(row1>max1){
                max1=row1;
                index = i;
            }
        }
        if(max1 == 0){
            return -1;
        }else{
            return index;
        }
        
	}

};

// { Driver Code Starts.
int main() {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    
    return 0;
}
  // } Driver Code Ends



// Optimal Solution - 

// - To solve in O(N + M) start from the top right corner of the matrix and keep 
// - Track of the index of the row which has maximum 1s. 
// - Go left if you encounter 1
// - Go down if you encounter 0
// - Stop when you reach the last row or first column. 


// int rowWithMax1s(vector<vector<int> > mat, int n, int m) {
// 	    int i=0,j=m-1,ans=-1;
// 	    while(i<n and j>=0){
// 	        if(mat[i][j]==1){
// 			   ans=i;
// 	            j--;
// 	        }
// 	        if(mat[i][j]==0){
// 	        i++;
// 	        }
// 	   }
// 	    return ans;
// 	}
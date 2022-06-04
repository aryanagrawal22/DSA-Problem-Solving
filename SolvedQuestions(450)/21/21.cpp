#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        //Calc Prefix sum and store it in a map
        int sum = 0;
        unordered_set<int> map;
        
        //If pref sum repeats then true or if pref sum is = 0 then true
        for (int i = 0; i<n; i++){
            sum += arr[i];
            if(sum==0 || map.find(sum)!=map.end()){
                return true;
            }
            map.insert(sum);
        }
        return false;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  
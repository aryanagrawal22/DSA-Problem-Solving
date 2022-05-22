// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    stack<char> stack;
    if(s.length()%2!=0){
        return -1;
    }
    
    for(int i=0; i< s.length(); i++){
        if(s[i]=='}' && !stack.empty()){
            if(stack.top()=='{'){
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }else{
            stack.push(s[i]);
        }
    }
    
    int leftLen = stack.size();
    
    int n = 0;
    while(!stack.empty() && stack.top()=='{'){
        stack.pop();
        n++;
    }
    
    return (leftLen / 2 + n % 2);
}
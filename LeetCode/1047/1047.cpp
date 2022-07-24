class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (int i = s.length()-1; i>=0; i--){
            if(!stk.empty()){
                if(stk.top()==s[i]){
                    stk.pop();
                }else{
                    stk.push(s[i]);
                }
            }else{
                stk.push(s[i]);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
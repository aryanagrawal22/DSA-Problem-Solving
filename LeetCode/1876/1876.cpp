class Solution {
public:
    int countGoodSubstrings(string s) {
        int start = 0, end = 0, ans = 0;
        for (int i = 0; i<s.length(); i++){
            if(i<2){
                end++;
            }else{
                if(s[end]!=s[end-1] && s[end]!=s[end-2] && s[end-1]!=s[end-2]) ans++;
                start++;
                end++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if(s[0]=='-') return false;
        
        int start = 0, end = s.length()-1;
        while(start<end){
            if(s[start]==s[end]) {
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};
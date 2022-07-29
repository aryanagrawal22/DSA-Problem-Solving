class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        while(start<end){
            while (isalnum(s[start]) == false && start < end) start++;
            while (isalnum(s[end]) == false && start < end) end--;
            if(toupper(s[start]) != toupper(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};
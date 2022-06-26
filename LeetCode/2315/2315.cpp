class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool flag = false;
        for (int i = 0; i<s.length(); i++){
            if(s[i]=='|') flag = !flag;
            else if(s[i]=='*' && !flag) count++;
        }
        return count;
    }
};
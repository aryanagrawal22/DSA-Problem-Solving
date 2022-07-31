class Solution {
public:
    string reverseOnlyLetters(string s) {
        int back = 0, front = s.length()-1;
        while(back<front){
            while(!isalpha(s[back]) && back<front) back++;
            while(!isalpha(s[front]) && back<front) front--;
            swap(s[back], s[front]);
            front--;
            back++;
        }
        return s;
    }
};
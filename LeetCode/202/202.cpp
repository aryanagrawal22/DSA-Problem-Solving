class Solution {
public:
    bool isHappy(int n) {
        map<int, int> map;
        while(n!=1){
            int temp = 0;
            while(n!=0){
                temp += pow((n%10), 2);
                n /= 10;
            }
            if(map[temp]) return false;
            else map[temp] = 1;
            n = temp;
        }
        return true;
    }
};
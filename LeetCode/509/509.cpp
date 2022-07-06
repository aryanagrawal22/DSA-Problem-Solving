class Solution {
public:
    int fib(int n) {
        int num1 = 0, num2 = 1, sum = 0;
        if(n==0) return num1;
        else if(n==1) return num2;
        else{
            for(int i = 1; i<n; i++){
                sum = num1 + num2;
                num1 = num2;
                num2 = sum;
            }
        }
        return sum;
    }
};
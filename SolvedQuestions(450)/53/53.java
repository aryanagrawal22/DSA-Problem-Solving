import java.io.*;
import java.util.*;

class Aryan {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solution obj = new Solution();
        String ans = obj.countAndSay(n);
        System.out.format("Count And Say of %d: %s", n, ans);
    }
}

class Solution {
    String countAndSay(int n) {
            if (n == 1) {
                return "1";
            }
            if (n == 2) {
                return "11";
            }

            String str = "11"; // Initialize previous term
            
            for (int i = 3; i <= n; i++) {
                str += '$';
                int len = str.length();

                int cnt = 1; // Initialize count of matching chars
                String tmp = ""; // Initialize i'th term in series
                char[] arr = str.toCharArray();
                for (int j = 1; j < len; j++) {
                    if (arr[j] != arr[j - 1]) {
                        tmp += cnt;
                        tmp += arr[j - 1];
                        cnt = 1;
                    }else{
                        cnt++;
                    }
                }
                str = tmp;
            }

            return str;

        }
}
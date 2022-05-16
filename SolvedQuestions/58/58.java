// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        String S = read.readLine();
        Solution ob = new Solution();
        System.out.println(ob.equal01(S));
    }
}

class Solution {
    static int equal01(String str) {
        int count0 = 0, count1 = 0, finalAns = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0') {
                count0++;
            } else {
                count1++;
            }
            if (count0 == count1) {
                finalAns++;
            }
        }

        if (count0 != count1) {
            return -1;
        }
        return finalAns;
    }
}
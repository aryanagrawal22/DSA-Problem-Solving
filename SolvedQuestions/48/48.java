// { Driver Code Starts
//Initial Template for Java

import java.io.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.isPalindrome(S));
        
    }
}// } Driver Code Ends


//User function Template for Java

class Solution {
    int isPalindrome(String S) {
        char ch[] = S.toCharArray();
        int start = 0;
        int end = ch.length-1;
        int c = 1;
        while(start<end){
            if (ch[start]==ch[end]){
                start++;
                end--;
            }else{
                c=0;
                break;
            }
        }
        return c;
    }
};
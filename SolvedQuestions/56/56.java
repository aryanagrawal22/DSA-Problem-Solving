import java.io.*;
import java.util.*;

class Aryan{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        Solution ob = new Solution();
        ob.solution(line);
    }
}

class Solution {
    static void solution(String s){
        for (int i=0; i<s.length(); i++){
            for (int j=i; j<=s.length(); j++){
                System.out.println(s.substring(i, j));
            }
        }
    }
}
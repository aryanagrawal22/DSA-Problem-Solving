import java.io.*;
import java.util.*;

class Aryan {
    public static void main(String args[]) throws IOException {
        Scanner sc= new Scanner(System.in); //System.in is a standard input stream  
        System.out.print("Enter a string1: ");  
        String str1= sc.nextLine();
        System.out.print("Enter a string2: ");  
        String str2= sc.nextLine(); 

        Solution obj = new Solution();
        boolean isFound = obj.rotateCheck(str1, str2);
        if(isFound){
            System.out.println("String 1 is rotated to form string 2");
        }else{
            System.out.println("String 1 is not rotated to form string 2");
        }
    }
}

class Solution {
    boolean rotateCheck(String S1, String S2) {
        String temp = S1+S1;
        if(temp.contains(S2)){
            return true;
        }
        return false;
    }
}
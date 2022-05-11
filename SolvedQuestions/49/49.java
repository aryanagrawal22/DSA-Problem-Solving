//Hello
import java.io.*;
import java.util.HashMap;

class Aryan {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        String inputString = read.readLine();
        Solution obj = new Solution();
        obj.repeated(inputString);
    }
}

class Solution {
    void repeated(String S) {
        HashMap<Character, Integer> map = new HashMap<>();
        char ch[] = S.toCharArray();
        for (int i =0; i<ch.length; i++){
            int count = map.getOrDefault(ch[i], 0);
            map.put(ch[i], count + 1);
        }
        map.entrySet().forEach(entry -> {
            if(entry.getValue()>1 && entry.getKey()!=' '){
                System.out.println(entry.getKey() + " " + entry.getValue());
            }
        });
    }
}
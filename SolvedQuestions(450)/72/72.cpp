// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
#include <map>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string str) {
        map <char, int> dict;
        int total=0;
        dict.insert(pair<char, int>('I', 1));
        dict.insert(pair<char, int>('V', 5));
        dict.insert(pair<char, int>('X', 10));
        dict.insert(pair<char, int>('L', 50));
        dict.insert(pair<char, int>('C', 100));
        dict.insert(pair<char, int>('D', 500));
        dict.insert(pair<char, int>('M', 1000));

        for (int i =0; i<str.length(); i++){
            
            if(int(str[i])<int(str[i+1])){
                char newchar1 = str[i];
                char newchar2 = str[i+1];
                auto found1 = dict.find(newchar1);
                auto found2 = dict.find(newchar2);
                total += ((found2->second)-(found1->second));
                i=i+1;
            }else{
                char newchar = str[i];
                auto found = dict.find(newchar);
                total += found->second;
            }
            
        }
        return total;
    }
};

// { Driver Code Starts.

int main() {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    
}  // } Driver Code Ends




// #include <bits/stdc++.h>
// using namespace std;
 
// // This function returns value
// // of a Roman symbol
// int value(char r)
// {
//     if (r == 'I')
//         return 1;
//     if (r == 'V')
//         return 5;
//     if (r == 'X')
//         return 10;
//     if (r == 'L')
//         return 50;
//     if (r == 'C')
//         return 100;
//     if (r == 'D')
//         return 500;
//     if (r == 'M')
//         return 1000;
 
//     return -1;
// }
 
// // Returns decimal value of
// // roman numaral
// int romanToDecimal(string& str)
// {
//     // Initialize result
//     int res = 0;
 
//     // Traverse given input
//     for (int i = 0; i < str.length(); i++) {
//         // Getting value of symbol s[i]
//         int s1 = value(str[i]);
 
//         if (i + 1 < str.length()) {
//             // Getting value of symbol s[i+1]
//             int s2 = value(str[i + 1]);
 
//             // Comparing both values
//             if (s1 >= s2) {
//                 // Value of current symbol
//                 // is greater or equal to
//                 // the next symbol
//                 res = res + s1;
//             }
//             else {
//                 // Value of current symbol is
//                 // less than the next symbol
//                 res = res + s2 - s1;
//                 i++;
//             }
//         }
//         else {
//             res = res + s1;
//         }
//     }
//     return res;
// }
 
// // Driver Code
// int main()
// {
//     // Considering inputs given are valid
//     string str = "MCMIV";
//     cout << "Integer form of Roman Numeral is "
//          << romanToDecimal(str) << endl;
 
//     return 0;
// }
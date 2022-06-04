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

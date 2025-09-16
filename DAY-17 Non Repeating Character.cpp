class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
    vector <int> f(256,0);
    
    for (char c : s) f[(unsigned char)c]++;
    
    for (char c : s){
        if (f[(unsigned char)c] == 1 ) return c;
    }
    return '$';
    }
};

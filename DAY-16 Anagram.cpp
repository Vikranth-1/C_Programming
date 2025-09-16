class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if (s1.size() != s2.size()) return false;
        vector<int> freq(256,0);
        
        for (char c : s1) freq[(unsigned char)c]++;
        for (char c : s2) freq[(unsigned char)c]--;
        
        for (int count : freq){
            if (count != 0) return false;
        }
        return true;
    }
};

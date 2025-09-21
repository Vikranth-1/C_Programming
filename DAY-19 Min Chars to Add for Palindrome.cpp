class Solution {
  public:
    int minChar(string &s) {
        // code here
        string r=s;
        reverse(r.begin(), r.end());
        string t = s + "#" +r;
        
        int n =t.size();
        vector <int> l(n,0);
        
        for (int i =1, k=0; i<n;){
            if (t[i] == t[k]) l[i++] = ++k;
            else if (k)k = l[k-1];
            else l[i++]=0;
        }
        return s.size() - l.back();
    }
};

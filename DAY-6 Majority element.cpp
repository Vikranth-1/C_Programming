class Solution {
  public:
    vector<int> findMajority(vector<int>& a) {
        // Code here
        int n=a.size();
        int c1=0, c2=0;
        int v1=0, v2=0;
        
        for (int x:a){
            if (x==c1) v1++;
            else if (x==c2) v2++;
            else if (v1 == 0) c1 = x, v1 = 1;
            else if (v2 == 0) c2 = x, v2 = 1;
            else v1--, v2--;
        }
        v1=v2=0;
        for (int x:a){
            if (x==c1) v1++;
            else if (x==c2) v2++;
        }
        vector<int> res;
        if (v1>n/3) res.push_back(c1);
        if (v2>n/3) res.push_back(c2);
        sort(res.begin(), res.end());
        return res;
    }
};

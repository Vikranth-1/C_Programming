class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> & v,
                                       vector<int> &n) {
        // code here
        vector<vector<int>> r;
        int i=0, sz=v.size();
        
        while (i<sz && v[i][1] < n[0]) r.push_back(v[i++]);
        
        while (i<sz && v[i][0] <= n[1]){
            n[0] = min(n[0], v[i][0]);
            n[1] = max(n[1], v[i][1]);
            i++;
        }
        r.push_back(n);
        
        while(i<sz) r.push_back(v[i++]);
        
        return r;
    }
};

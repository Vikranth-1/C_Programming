class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& v) {
        // Code here
        if (v.empty()) return {};
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        res.push_back(v[0]);
        
        for (int i=1; i<v.size(); i++){
            if (v[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], v[i][1]);
            else
                res.push_back(v[i]);
        }
        return res;
    }
};

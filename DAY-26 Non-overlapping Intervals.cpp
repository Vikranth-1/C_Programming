class Solution {
  public:
    int minRemoval(vector<vector<int>> & v) {
        // code here
        if(v.empty()) return 0;
        sort(v.begin(), v.end(), [](auto &a, auto &b){ return a[1]<b[1];});
        
        int cnt =0, end = v[0][1];
        for (int i=1; i<v.size(); i++){
            if (v[i][0] < end ) cnt++;
            else end =v[i][1];
        }
        return cnt;
    }
};

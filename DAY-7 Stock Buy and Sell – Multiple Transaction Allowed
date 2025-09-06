class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        int n=p.size(), ans=0;
        for (int i = 1;i<n;i++){
            if (p[i]>p[i-1]) ans+=p[i]-p[i-1];
        }
        return ans;
    }
};

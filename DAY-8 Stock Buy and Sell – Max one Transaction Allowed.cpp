class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        // code here
        int n=p.size();
        if (n==0) return 0;
        int mn=p[0], ans=0;
        
        for (int i=1;i<n;i++){
            ans = max(ans, p[i]-mn);
            mn = min(mn, p[i]);
        }
        return ans;
    }
};

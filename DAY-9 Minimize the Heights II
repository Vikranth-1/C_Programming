class Solution {
  public:
    int getMinDiff(vector<int> &a, int k) {
        // code here
        int n=a.size();
        if (n==1) return 0;
        
        sort(a.begin(), a.end());
        int ans = a[n-1] - a[0];
        int mn =a[0]+k , mx=a[n-1]-k;
        
        for(int i=0;i<n-1;i++){
            int lo=min(mn, a[i+1] -k);
            int hi=max(mx,a[i]+k);
            if (lo<0) continue;
            ans=min(ans,hi-lo);
        }
        return ans;
    }
};

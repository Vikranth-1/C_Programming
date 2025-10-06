class Solution {
  public:
    int search(vector<int>& a, int k) {
        // Code Here
        int l=0, r=a.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==k) return m;
            if(a[l]<=a[m]){
                if(k>=a[l] && k<a[m]) r=m-1;
                else l=m+1;
            }else{
                if(k>a[m] && k<=a[r]) l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};

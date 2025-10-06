class Solution {
  public:
    int findMin(vector<int>& a) {
        // complete the function here
        int l=0, r=a.size()-1;
        while(l<r){
            int m= l + (r-l)/2;
            if(a[m]>a[r]) l=m+1;
            else r=m;
        }
        return a[l];
    }
};

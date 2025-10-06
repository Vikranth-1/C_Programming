class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(), m=b.size();
        int g=(n+m+1)/2;
        while (g>0){
            int i=0, j=g;
            while(j<n+m){
                int &x=(i<n)?a[i]:b[i-n];
                int &y=(j<n)?a[j]:b[j-n];
                if(x>y) swap(x,y);
                i++; j++;
            }
            if(g==1) break;
            g=(g+1)/2;
        }
    }
};

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &a) {
        // code here
        int r=a.size();
        int c=a[0].size();
        
        int t=0,b=r-1;
        int l=0,rt=c-1;
        
        vector<int> v;
        while (t<=b && l<=rt){
            for (int j=l; j<=rt; j++)
                v.push_back(a[t][j]);
            t++;
            
            for(int i=t;i<=b;i++)
                v.push_back(a[i][rt]);
            rt--;
            
            if (t<=b){
                for(int j=rt; j>=l; j--)
                    v.push_back(a[b][j]);
                b--;
            }
            
            if (l<=rt){
                for(int i=b; i>=t; i--)
                    v.push_back(a[i][l]);
                l++;
            }
        }
        return v;
    }
};

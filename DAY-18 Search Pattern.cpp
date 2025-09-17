class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<int> l(m,0) , ans;
        
        for (int i=1,k =0;i<m;){
            if (pat[i] == pat[k]) l[i++]=++k;
            else if (k) k =l[k-1];
            else l[i++] = 0;
        }
        
        for (int i=0,j=0;i<n;){
            if (txt[i] == pat[j]) { i++; j++;}
            if (j==m){
                ans.push_back(i-j);
                j=l[j-1];
            }else if(i<n && txt[i] != pat[j]){
                if (j)j=l[j-1];
                else i++;
            }
        }
        return ans;
    }
};

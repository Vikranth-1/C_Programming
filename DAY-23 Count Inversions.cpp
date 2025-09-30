class Solution {
  public:
    long long mrg(vector<int>&a,int l,int m, int r){
        vector<int> L(a.begin()+l, a.begin()+m+1);
        vector<int> R(a.begin()+m+1, a.begin()+r+1);
        int i=0, j=0, k=l;
        long long c=0;
        
        while (i<L.size() && j<R.size()){
            if (L[i]<= R[j]) a[k++] = L[i++];
            else{
                a[k++]=R[j++];
                c+= (L.size()-i);
            }
        }
        
        while(i<L.size()) a[k++] = L[i++];
        while(j<R.size()) a[k++] = R[j++];
        return c;
    }
    
    long long mrgsrt(vector<int>& a, int l, int r){
        if(l>=r) return 0;
        int m=(l+r)/2;
        long long c=0;
        c+= mrgsrt(a,l,m);
        c+= mrgsrt(a,m+1,r);
        c+= mrg(a,l,m,r);
        return c;
    }
    
    long long inversionCount(vector<int> &arr) {
        // Code Here
        return mrgsrt(arr,0,arr.size()-1);
    }
};

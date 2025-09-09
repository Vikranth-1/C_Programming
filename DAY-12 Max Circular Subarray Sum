class Solution {
  public:
  
    int kadane(vector<int> &a){
        int best=a[0], cur=a[0];
        for (int i=1;i<a.size();i++){
            cur=max(a[i],cur+a[i]);
            best=max(best,cur);
        }
        return best;
    }
    int maxCircularSum(vector<int> &a) {
        // code here
        int n=a.size();
        int no=kadane(a);
        if (no<0) return no;
        
        int sum=0;
        for (int i=0;i<n;i++){
            sum += a[i];
            a[i] = -a[i];
        }
        
        int minsub=kadane(a);
        int wrap=sum+minsub;
        
        return max(no,wrap);
    }
};

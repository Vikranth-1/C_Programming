class Solution {
  public:
  
    bool canPlace(vector<int>& s, int k, int d){
        int cows = 1, last =s[0];
        for (int i=1;i<s.size();i++){
            if(s[i] - last >= d){
                cows++;
                last = s[i];
                if (cows == k) return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int low =1 , high= stalls.back() - stalls.front(), ans=0;
        while (low <=high) {
            int mid = low + (high -low) /2;
            if (canPlace(stalls,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid -1;
            }
        }
        return ans;
    }
};

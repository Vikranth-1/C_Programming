class Solution {
  public:
    int countOccurrences(vector<int>& arr, int x) {
        int n = arr.size();
        
        // find first occurrence
        int l=0, r=n-1, first=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==x){
                first=mid;
                r=mid-1; // move left
            } 
            else if(arr[mid]<x) l=mid+1;
            else r=mid-1;
        }
        
        if(first==-1) return 0; // not found
        
        // find last occurrence
        l=0, r=n-1;
        int last=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x){
                last=mid;
                l=mid+1; // move right
            }
            else if(arr[mid]<x) l=mid+1;
            else r=mid-1;
        }
        
        return last-first+1;
    }
};

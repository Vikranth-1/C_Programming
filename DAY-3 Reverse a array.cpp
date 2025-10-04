class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n=arr.size();
        int ar[n];
        for (int i=0;i<n;i++){
            ar[i]=arr[n-i-1];
        }
        for (int i=0;i<n;i++){
            arr[i]=ar[i];
        }
    }
};

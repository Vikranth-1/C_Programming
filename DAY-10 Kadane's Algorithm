int maxSubarraySum(int arr[], int n) {
    // Code here
    int m=arr[0];
    int c=arr[0];
    
    for (int i=1;i<n;i++){
        if (c+arr[i]>arr[i]){
            c=c+arr[i];
        }
        else{
            c=arr[i];
        }
        if (c>m){
            m=c;
        }
    }
    return m;
}

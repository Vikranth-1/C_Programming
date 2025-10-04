int getSecondLargest(int *arr, int n) {
    // code here
    int i,m,s;
    m=s=-1;
    for (i=0;i<n;i++){
        if (arr[i]>m){
            s=m;
            m=arr[i];
        }
        else if(arr[i]!=m && arr[i]>=s){
            s=arr[i];
        }
    }
    return s;
}

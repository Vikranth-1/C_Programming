int maxProduct(int arr[], int n) {
    int mf=arr[0];
    int ma=arr[0];
    int mi=arr[0];
    for (int i=1;i<n;i++){
        if (arr[i]<0){
            int t=mi;
            mi=ma;
            ma=t;
        }
    ma=(arr[i]>ma*arr[i]) ? arr[i] : ma*arr[i];
    mi=(arr[i]<mi*arr[i]) ? arr[i] : mi*arr[i];
    mf=(mf>ma) ? mf : ma;
    }
    return mf;
}

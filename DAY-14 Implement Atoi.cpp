class Solution{
    public:
    int myAtoi(string& s){
        int i=0, n=s.size();
        long long result = 0;
        int sign =1;
        
        while (i<n && s[i] == ' ') i++;
        if (i<n && (s[i]=='+'|| s[i]=='-')){
            sign=(s[i] == '-') ?-1:1;
            i++;
        }
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if (result > (LLONG_MAX -digit) / 10) {
                return (sign == 1 ) ? INT_MAX : INT_MIN;
            }
            result =result *10 + digit;
            i++;
            
        }
        result *= sign;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return (int) result;
    } 
};

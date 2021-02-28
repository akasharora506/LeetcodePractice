class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend== INT32_MIN && divisor == -1) return INT_MAX;
        if(divisor==1) return dividend;
        bool isNeg= !((dividend>0)==(divisor>0));
        long a = abs(dividend);
        long b = abs(divisor);
        int ans=0;
        while(a>=b){
            int x=0;
            while(a-(b<<1<<x)>=0)
                x++;
            ans+=1<<x;
            a-=b<<x;
        };
        cout<<isNeg<<endl;
        return isNeg?-ans:ans;
    }
};
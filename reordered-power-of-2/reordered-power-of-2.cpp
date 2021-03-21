class Solution {
public:
    vector<int> giveDigits(int n){
        vector<int> ans(10,0);
        while(n){
            ans[n%10]++;
            n/=10;
        };
        return ans;
    }; 
    bool reorderedPowerOf2(int N) {
        vector<int> digitN=giveDigits(N);
        for(long long int i=1;i<=1e9;i*=2){
            if(giveDigits(i)==digitN)
                return true;
        };
        return false;
    }
};
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=0;i<=num;i++){
            ans[i]=__builtin_popcount(i);
        };
        return ans;
    }
};
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n=nums.size();
        bitset<10000> b;
        for(int i:nums){
            if(b.test(i-1)){
                ans[0]=i;
            }else{
                b.set(i-1);
            };
        };
        for(int i=0;i<n;i++){
            if(!b.test(i)){
                ans[1]=i+1;
            };
        };
        return ans;
    }
};
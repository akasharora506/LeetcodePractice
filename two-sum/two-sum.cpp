class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]=i;
        };
        vector<int> ans(2,-1);
        for(int i=0;i<n;i++){
            if(hash.find(target-nums[i])!=hash.end()&&i!=hash[target-nums[i]]){
                ans[0]=i;
                ans[1]=hash[target-nums[i]];
            };
        };
        return ans;
    }
};
class Solution {
public:
    long dfs(vector<int>& nums, long S,bool plus,int curr=0){
        if(curr==nums.size()-1){
            return (plus&&S==nums[curr])||(!plus&&S==-nums[curr]);
        };
        long next=plus?S-nums[curr]:S+nums[curr];
        return dfs(nums,next,plus,curr+1)+dfs(nums,next,!plus,curr+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums,S,0)+dfs(nums,S,1);
    }
};
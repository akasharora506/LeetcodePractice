class Solution {
public:
    void recur(vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums, int curr, int n){
        if(curr>=n){
            ans.push_back(temp);
            return;
        };
        temp.push_back(nums[curr]);
        recur(ans,temp,nums,curr+1,n);
        temp.pop_back();
        recur(ans,temp,nums,curr+1,n);
    };
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(ans,temp,nums,0,nums.size());
        return ans;
    }
};
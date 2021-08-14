class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i:nums){
            int ind=abs(i)-1;
            nums[ind]=-abs(nums[ind]);
        };
        for(int i=0;i<n;i++){
            if(nums[i]>0)ans.push_back(i+1);
        };
        return ans;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int in=abs(nums[i])-1;
            if(nums[in]>0){nums[in]= -1*nums[in];}
        };
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            };
        };
        return ans;
    }
};
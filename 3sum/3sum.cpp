class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int val=nums[i]+nums[j]+nums[k];
                if(val==0){
                    vector<int> curr={nums[i],nums[j],nums[k]};
                    ans.insert(curr);
                    j++;
                    k--;
                }else if(val>0){
                    k--;
                }else{
                    j++;
                };
            };
        }
        vector<vector<int>> finalAns;
        for(auto i: ans){
            finalAns.push_back(i);
        };
        return finalAns;
    }
};
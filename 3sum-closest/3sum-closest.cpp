class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int curr=nums[l]+nums[r]+nums[i];
                if(abs(target-curr)<diff){
                    ans=curr;
                    diff=abs(target-curr);
                };
                if(curr==target)return target;
                if(curr>target)r--;
                else l++;
                
            };
        };
        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> prefix(n,0);
        mp[0]=1;
        for(int i=0;i < n;i++)
        {
            if(i == 0)
            {
                prefix[i]+=nums[i];
            }
            else
            {
                prefix[i]=prefix[i-1]+nums[i];
            }
        }
        for(int i=0;i < prefix.size();i++)
        {
            if(mp.count(prefix[i] - k))
            {
                ans+=mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};
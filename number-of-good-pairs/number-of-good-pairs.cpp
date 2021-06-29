class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i:nums)f[i]++;
        int ans=0;
        for(auto i:f){
            ans+=i.second*(i.second-1)/2;
        };
        return ans;
    }
};
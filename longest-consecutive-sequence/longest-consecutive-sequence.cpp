class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i:nums)m[i]=1;
        for(auto i:m){
            int curr=i.first,c=0;
            if(m.count(curr-1))continue;
            while(m.count(curr++))c++;
            ans=max(ans,c);
        };
        return ans;
    }
};
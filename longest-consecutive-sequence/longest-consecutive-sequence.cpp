class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
            return n;
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=1;
        for(int i: nums){
            if(s.find(i-1)==s.end()){
                int curr=1;
                int num=i+1;
                while(s.find(num)!=s.end())
                    num++,curr++;
                ans=max(ans,curr);
            };
        }
        return ans;
    }
};
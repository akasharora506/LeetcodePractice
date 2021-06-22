class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> v;
        int i=0,n=nums.size();
        while(i<n){
            while(i<n&&nums[i]!=1)i++;
            if(i==n)break;
            int j=i+1;
            while(j<n&&nums[j]!=0)j++;
            v.push_back({i,j-1});
            i=j;
        };
        sort(v.begin(),v.end());
        n=v.size();
        if(!v.size())return 0;
        int ans=count(nums.begin(),nums.end(),0)?v[0].second-v[0].first+1:v[0].second-v[0].first;
        for(int i=0;i<n-1;i++){
            auto a=v[i],b=v[i+1];
            int as=a.second-a.first+1,bs=b.second-b.first+1;
            ans=max(ans,max(as,bs));
            if(b.first-a.second==2)ans=max(ans,as+bs);
        };
        return ans;
    }
};
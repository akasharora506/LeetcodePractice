class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        vector<vector<int>> h(n+1);
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        };
        for(auto i:m){
            h[i.second].push_back(i.first);
        };
        for(int j=n;j>=0,k;j--){
            while(k&&!h[j].empty()){
                ans.push_back(h[j][h[j].size()-1]);
                h[j].pop_back();
                k--;
            };
        };
        return ans;
    }
};
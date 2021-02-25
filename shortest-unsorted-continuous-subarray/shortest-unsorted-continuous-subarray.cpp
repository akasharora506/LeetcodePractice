class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=n-1,r=0;
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&nums[i]<nums[s.top()]){
                l=min(l,s.top());
                s.pop();
            };
            s.push(i);
        };
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&nums[i]>nums[s.top()]){
                r=max(r,s.top());
                s.pop();
            };
            s.push(i);
        };
        return r>l?r-l+1:0;
    }
};
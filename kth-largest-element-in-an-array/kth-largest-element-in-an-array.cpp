class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(),nums.end());
        while(k!=1){
            p.pop();
            k--;
        };
        return p.top();
    }
};
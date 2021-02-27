class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(i);
        };
        for(int i:nums)s.erase(i);
        
        return !s.empty()?*s.begin():nums.size();
    }
};
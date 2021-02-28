class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums)s.insert(i);
        return s.size()!=nums.size();
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sumShouldBe= n*(n+1)/2;
        int sumIs=0;
        for(int i:nums) sumIs+=i;
        return abs(sumIs-sumShouldBe);
        
    }
};
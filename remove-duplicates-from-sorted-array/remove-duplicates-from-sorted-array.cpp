class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int indexLastDistinct=0,curr=1,n=nums.size();
        // while(curr<n){
        //     if(nums[curr]>nums[indexLastDistinct]){
        //         nums[indexLastDistinct+1]=nums[curr];
        //         indexLastDistinct++;
        //     };
        //     curr++;
        // };
        // nums.resize(min(n,indexLastDistinct+1));
        // return nums.size();
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};
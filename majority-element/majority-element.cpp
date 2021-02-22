class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==cand){
                c++;
            }else{
                c--;
            };
            if(c==0){
                cand=nums[i];
                c=1;
            };
        };
        return count(nums.begin(),nums.end(),cand) > nums.size()/2 ? cand : -1;
    }
};
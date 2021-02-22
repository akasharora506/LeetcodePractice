class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[i]==0){
                swap(nums[i],nums[j++]);
            }else if(i<j){
                i++;
            }else{
                i++;
                j++;
            };;
        };
    }
};
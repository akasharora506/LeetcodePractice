class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> inc(n),dec(n);
        inc[0]=dec[0]=1;
        for(int i=1;i<n;i++){
            inc[i]=dec[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j])inc[i]=max(inc[i],1+dec[j]);
                if(nums[i]<nums[j])dec[i]=max(dec[i],1+inc[j]);
            };
        };
        return max(inc[n-1],dec[n-1]);
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> wf(n,0);
        int ans=0;
        int i=0,j=0;
        int flips=k;
        while(j<n){
            if(nums[j]){
                j++;
                ans=max(ans,j-i);
            }else if(flips){
                wf[j]=1;
                j++;
                flips--;
                ans=max(ans,j-i);
            }else{
                flips+=wf[i];
                wf[i]=0;
                i++;
                j=max(i,j);
            };
        };
        return ans;
    }
};
class Solution {
public:
    bool helper(vector<int> &nums,int s,int e,bool currentPlayer,int scoreP1,int scoreP2){
        // base condition
      if(s>e){
          // cout<<scoreP1<<" "<<scoreP2<<endl;
          return scoreP1>=scoreP2;
      };  
        // recall
        if(currentPlayer==0){
            bool choseFront=helper(nums,s+1,e,!currentPlayer,scoreP1+nums[s],scoreP2);
            bool choseBack=helper(nums,s,e-1,!currentPlayer,scoreP1+nums[e],scoreP2);
            return choseFront||choseBack;
        }else{
            bool choseFront=helper(nums,s+1,e,!currentPlayer,scoreP1,scoreP2+nums[s]);
            bool choseBack=helper(nums,s,e-1,!currentPlayer,scoreP1,scoreP2+nums[e]);
            return choseFront&&choseBack;
        };
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1,0,0,0);
    }
};
   
            
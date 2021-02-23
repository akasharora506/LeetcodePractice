class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> ans(n);
        reverse(T.begin(),T.end());
        stack<int> s;
        s.push(0);
        ans[0]=0;
        for(int i=1;i<n;i++){
            while(!s.empty()&&T[i]>=T[s.top()]){
                s.pop();
            };
            if(s.empty()){
                ans[i]=0;
            }else{
                ans[i]=i-s.top();
            };
            s.push(i);
        };
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
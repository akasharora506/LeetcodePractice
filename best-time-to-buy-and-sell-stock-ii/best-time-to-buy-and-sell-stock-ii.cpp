class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,i=1,n=prices.size();
        stack<int> s;
        s.push(prices[0]);
        while(i<n){
            if(prices[i]>s.top()){
                ans+=(prices[i]-s.top());
                s.push(prices[i]);
            };
            s.push(prices[i++]);
        };
        return ans;
    }
};
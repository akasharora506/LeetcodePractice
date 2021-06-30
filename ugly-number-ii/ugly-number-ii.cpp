class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1,1);
        int i=0,j=0,k=0;
        while(ans.size()<n){
            int a=ans[i]*2,
            b=ans[j]*3,
            c=ans[k]*5;
            ans.push_back(min({a,b,c}));
            if(ans.back()==a)i++;
            if(ans.back()==b)j++;
            if(ans.back()==c)k++;
        };
        return ans[n-1];
    }
};
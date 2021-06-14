class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]==b[1]?a[0]>b[0]:a[1]>b[1];
    };
    int maximumUnits(vector<vector<int>>& b, long long t) {
        sort(b.begin(),b.end(),comp);
        long long ans=0,i=0;
        while(t>0&&i<b.size()){
            if(t>=b[i][0]){
                t-=b[i][0];
                ans+=b[i][0]*b[i][1];
            }else{
                ans+=t*b[i][1];
                t=0;
            };
            i++;
        };
        return ans;
    }
};
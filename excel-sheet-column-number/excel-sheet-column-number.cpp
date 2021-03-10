class Solution {
public:
    int cti(char a){
        return a-'A'+1;
    }
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n=columnTitle.length();
        for(int i=n-1;i>=0;i--){
            ans+=pow(26,n-i-1)*cti(columnTitle[i]);
        };
        return ans;
    }
};
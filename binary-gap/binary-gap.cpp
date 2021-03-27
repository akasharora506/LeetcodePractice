class Solution {
public:
    int binaryGap(int n) {
        string s;
        while(n){
            s+=to_string(n&1);
            n>>=1;
        };
        vector<int> v;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                v.push_back(i);
            };
        };
        for(int i=0;i<v.size()-1;i++){
            ans=max(v[i+1]-v[i],ans);
        };
        return ans;
    }
};
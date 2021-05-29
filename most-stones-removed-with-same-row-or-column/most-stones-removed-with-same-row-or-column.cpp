class Solution {
public:
    int find(vector<int> &p,int i){
        if(p[i]==-1)
            return i;
        return p[i]=find(p,p[i]);
    }
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        vector<int> p(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i][0]==s[j][0]||s[i][1]==s[j][1]){
                    int pi=find(p,i),pj=find(p,j);
                    if(pi!=pj){
                        p[pj]=pi;
                    };
                };
            };
        };
        for(int i:p){
            if(i==-1)
                n--;
        };
        return n;
    }
};
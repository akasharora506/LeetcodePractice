class Solution {
public:
    vector<int> p;
    int find(int a){
        if(p[a]==-1)
            return a;
        return p[a]=find(p[a]);
    }
    bool merge(int a,int b){
        int pa=find(a),pb=find(b);
        if(pa==pb)
            return false;
        p[pb]=pa;
        return true;
    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        p.resize(n);
        fill(p.begin(),p.end(),-1);
        unordered_map<int,int> m;
        vector<int> ans1,ans2;
        for(auto e:edges){
            int a=e[0]-1,b=e[1]-1;
            if(m.find(b)!=m.end()){
                ans1={m[b]+1,b+1};
                ans2=e;
            };
            m[b]=a;
        };
        for(auto e:edges){
            int a=e[0]-1,b=e[1]-1;
            if(e==ans2)
                continue;
            if(!merge(a,b)){
                return ans1.empty() ? e : ans1;
            };
        };
        return ans2;
    }
};
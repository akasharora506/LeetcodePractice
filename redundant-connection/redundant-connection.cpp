class Solution {
public:
    class DSU{
        public:
        vector<int> p,r;
        DSU(int m){
            p.resize(m);
            fill(p.begin(),p.end(),-1);
            r.resize(m);
            fill(r.begin(),r.end(),1);
        };
        int find(int a){
            if(p[a]==-1)
                return a;
            return p[a]=find(p[a]);
        };
        bool merge(int a,int b){
            int pa=find(a),pb=find(b);
            if(pa==pb)
                return false;
            if(r[pa]>=r[pb]){
                p[pb]=pa;
                r[pa]+=r[pb];
                r[pb]=0;
            }else{
                p[pa]=pb;
                r[pb]+=r[pa];
                r[pa]=0;
            };
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU s(n);
        for(auto e:edges){
            int a=e[0]-1,b=e[1]-1;
            if(!s.merge(a,b))
                return e;
        };
        return {};
    }
};
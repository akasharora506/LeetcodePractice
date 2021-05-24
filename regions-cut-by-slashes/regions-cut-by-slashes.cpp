class Solution {
public:
    int find(vector<int> &par,int a){
        if(par[a]==-1)
            return a;
        return par[a]=find(par,par[a]);
    };
    void merge(vector<int> &par,vector<int> &rank, int a,int b){
        if(a<0||b<0||a>=par.size()||b>=par.size())
            return;
        int pa=find(par,a),pb=find(par,b);
        if(pa!=pb){
            if(rank[pa]>=rank[pb]){
                par[pb]=pa;
                rank[pa]+=rank[pb];
                rank[pb]=0;
            }else{
                par[pa]=pb;
                rank[pb]+=rank[pa];
                rank[pa]=0;
            };
        };
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<int> par(4*n*n,-1),rank(4*n*n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].length();j++){
                int sq=4*(n*i+j);
                if(grid[i][j]==' '){
                    merge(par,rank,sq,sq+1);
                    merge(par,rank,sq+2,sq+3);
                    merge(par,rank,sq,sq+3);
                }else if(grid[i][j]=='/'){
                    merge(par,rank,sq,sq+3);
                    merge(par,rank,sq+1,sq+2);
                }else{
                    merge(par,rank,sq,sq+1);
                    merge(par,rank,sq+2,sq+3);
                };
                int topBox=4*(n*(i-1)+j)+2;
                int bottomBox=4*(n*(i+1)+j);
                int rightBox=4*(n*i+j+1)+3;
                int leftBox=4*(n*i+j-1)+1;
                if(i!=0)merge(par,rank,sq,topBox);
                if(j!=grid[i].length()-1)merge(par,rank,sq+1,rightBox);
                if(j!=0)merge(par,rank,sq+3,leftBox);
                if(i!=n-1)merge(par,rank,sq+2,bottomBox);
            };
        };

        return count(par.begin(),par.end(),-1);
    }
};
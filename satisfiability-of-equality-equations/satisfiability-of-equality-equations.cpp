class Solution {
public:
    vector<char> par;
    vector<int> rank;
    Solution(){
        for(int i=0;i<26;i++)
            par.push_back('-'),rank.push_back(1);
    }
    char find(char a){
        if(par[a-'a']=='-')
            return a;
        return par[a-'a']=find(par[a-'a']);
    };
    void merge(char a,char b){
        if(rank[a-'a']>rank[b-'a']){
            par[b-'a']=a;
            rank[a-'a']+=rank[b-'a'];
            rank[b-'a']=0;
        }else{
            par[a-'a']=b;
            rank[b-'a']+=rank[a-'a'];
            rank[a-'a']=0;
        };
    };
    bool equationsPossible(vector<string>& equations) {
        for(auto e:equations){
            char a=e[0],b=e[3];
             if(e[1]=='='){
                 char pa=find(a),pb=find(b);
                 if(pa!=pb){
                     merge(pa,pb);
                 };
             };
                 
        };
        for(auto e:equations){
            char a=e[0],b=e[3];
             if(e[1]=='!'&&find(a)==find(b))
                 return false;
        };
        return true;
    }
};
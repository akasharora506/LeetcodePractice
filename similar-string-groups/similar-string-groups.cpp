class Solution {
public:
    void dfs(unordered_map<string,vector<string>> &g,unordered_set<string> &v,string i){
        if(v.find(i)==v.end())
            return;
        v.erase(i);
        for(string j:g[i]){
            if(v.find(j)!=v.end()){
                dfs(g,v,j);
                v.erase(j);
            };
        };
    }
    bool aosa(string a,string b){
        int ans=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])ans++;
        };
        return ans==2;
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string,vector<string>> g;
        unordered_set<string> v(strs.begin(),strs.end());
        if(v.size()==1)
            return 1;
        int ans=0;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[i]==strs[j]||i==j)continue;
                g[strs[i]].push_back("");
                g[strs[i]].pop_back();
                if(aosa(strs[i],strs[j])){
                    g[strs[i]].push_back(strs[j]);
                };
            };
        };   
        for(auto i:g){
            if(v.find(i.first)!=v.end()){
                dfs(g,v,i.first);
                v.erase(i.first);
                ans++;
            };
        };
        return ans;
    }
};
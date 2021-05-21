class Solution {
public:
    double dfs(unordered_map<string,unordered_map<string,double>> &graph,unordered_set<string>& vis, string curr,string target){
        if(graph[curr].find(target)!=graph[curr].end())
            return graph[curr][target];
        for(auto nbr:graph[curr]){
            if(find(vis.begin(),vis.end(),nbr.first)!=vis.end()){
                continue;
            };
            vis.insert(curr);
            double x=dfs(graph,vis,nbr.first,target);
            if(x==-1.00000)
                continue;
            return x*nbr.second;
        }            
        return -1.00000;
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]]=values[i];
            graph[equations[i][1]][equations[i][0]]=1.0/values[i];
        };
        for(auto query:queries){
            string src=query[0],target=query[1];
            unordered_set<string> vis;
            ans.push_back(dfs(graph,vis,src,target));
        };
        return ans;
    }
};
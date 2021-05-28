class Solution {
public:
    // Kahn's Algo for topological sort
    vector<int> topoSort(vector<unordered_set<int>> &g,vector<int> &indegree){
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            };
        };
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int nbr:g[cur]){
                indegree[nbr]--;
                if(!indegree[nbr]){
                    q.push(nbr);
                };
            };
        };
        for(int i:indegree){
            if(i>0)
                return {};
        };
        return ans;
    };
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // put the groupless items into their own group
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m++;
            };
        };
        // build graph
        vector<unordered_set<int>> gg(m),gi(n);
        vector<int> vg(m),vi(n);
        for(int i=0;i<n;i++){
            int toGroup=group[i];
            for(int j:beforeItems[i]){
                int fromGroup=group[j];
                if(fromGroup!=toGroup and !gg[fromGroup].count(toGroup)){
                    gg[fromGroup].insert(toGroup);
                    vg[toGroup]++;
                };
                if(i!=j&&!gi[j].count(i)){
                    gi[j].insert(i);
                    vi[i]++;
                };
            };
        };
        // topological sort
        vector<int> itemSorted=topoSort(gi,vi);
        vector<int> groupSorted=topoSort(gg,vg);
        if(itemSorted.empty()||groupSorted.empty())
            return {};
        vector<int> ans;
        vector<vector<int>> groupsWithItemSorted(m);
        for(auto item:itemSorted){
            groupsWithItemSorted[group[item]].push_back(item);
        };
        for(auto gs:groupSorted){
            for(auto item:groupsWithItemSorted[gs]){
                ans.push_back(item);
            };
        };
        return ans;
        
    }
};
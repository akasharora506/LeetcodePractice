class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int maxStop=0;
        if(source==target)
            return 0;
        for(auto i:routes){
            for(auto j:i){
                maxStop=max(j,maxStop);
            };
        };
        vector<vector<int>> graph(maxStop+1);
        for(int i=0;i<routes.size();i++){
            for(auto j:routes[i]){
                graph[j].push_back(i);
            };
        };
        vector<int> visited(maxStop+1,0);
        queue<pair<int,int>> onBus;
        onBus.push({source,0});
        visited[source]=1;
        while(!onBus.empty()){
            auto curr=onBus.front();
            onBus.pop();
            int stop=curr.first,bus=curr.second;
            for(auto route:graph[stop]){
                if(routes[route].empty())
                    continue;
                for(auto nbr:routes[route]){
                    if(visited[nbr])
                        continue;
                    onBus.push({nbr,bus+1});
                    visited[nbr]=1;
                    if(nbr==target)
                        return bus+1;
                };
                routes[route].clear();
            };
        };
        return -1;
        
    }
};
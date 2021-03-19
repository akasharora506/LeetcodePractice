class Solution {
public:
    void dfs(vector<vector<int>> &graph, bitset<1000> &visited, int start=0){
        if(visited.test(start))
            return;
        visited.set(start);
        for(int i: graph[start]){
            dfs(graph,visited,i);
        };
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bitset<1000> visited;
        dfs(rooms,visited);
        return visited.count()==rooms.size();
    }
};
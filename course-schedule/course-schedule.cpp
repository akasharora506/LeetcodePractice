class Solution {
public:
    bool isCyclic(vector<vector<int>> &g, vector<int> &visited,vector<int> &stack,int curr){ 
        if(stack[curr])
            return true;
        if(visited[curr])
            return false;
        visited[curr]=true;
        stack[curr]=true;
        for(int nbr:g[curr]){
            if(isCyclic(g,visited,stack,nbr))
                return true;
        };
        stack[curr]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto i:prerequisites){
            g[i[0]].push_back(i[1]);
            if(i[0]==i[1])
                return false;
        };
        vector<int> visited(numCourses,0),stack(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(isCyclic(g,visited,stack,i))
                return false;
        };
        return true;
    }
};
class Solution {
public:
    string convertBoard(vector<vector<int>> &a){
        string s;
        for(auto i:a){
            for(auto j:i){
                s+=to_string(j);
            };
        };
        return s;
    };
    vector<vector<vector<int>>> findNbr(vector<vector<int>>& g){
        int x=0,y=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(g[i][j]==0){
                    x=i;
                    y=j;
                };
            };
        };
        vector<vector<vector<int>>> nbrs;
        vector<int> dir{1,0,-1,0};
        for(int i=0;i<4;i++){
            vector<vector<int>> nbr=g;
            int newX=x+dir[i],
            newY=y+dir[(i+1)%4];
            if(newX<0||newX>=2||newY<0||newY>=3)continue;
            swap(nbr[x][y],nbr[newX][newY]);
            nbrs.push_back(nbr);
        };
        return nbrs;
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        unordered_map<string,int> m,dist;
        string sol="123450";
        if(convertBoard(board)==sol)
            return 0;
        q.push(board);
        m[convertBoard(board)]=1;
        dist[convertBoard(board)]=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto nbr: findNbr(curr)){
                if(!m[convertBoard(nbr)]){
                    dist[convertBoard(nbr)]=dist[convertBoard(curr)]+1;
                    m[convertBoard(nbr)]=1;
                    q.push(nbr);
                };
            };
        };
        return dist[sol]?dist[sol]:-1;
    }
};
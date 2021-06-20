class Trie{
    public:
    unordered_map<char,Trie*> m;
    string word="";
    bool wordEnd=false;
    Trie(){}
    Trie(vector<string> &b){
        for(string word:b)this->insert(word);
    };
    void insert(string word){
        auto root=this;
        for(char i:word){
            if(!root->m[i])root->m[i]=new Trie();
            string newWord=root->word+i;
            root=root->m[i];
            root->word=newWord;
        };
        root->wordEnd=true;
    };
};
void dfs(Trie* root,vector<vector<char>> &b,vector<string> &ans,int m,int n,int i,int j){
    if(i<0||j<0||i>=m||j>=n||b[i][j]=='$'||!root->m[b[i][j]]){
        if(root&&root->wordEnd)ans.push_back(root->word);
        return;
    };
    char temp=b[i][j];
    b[i][j]='$';
    dfs(root->m[temp],b,ans,m,n,i+1,j);
    dfs(root->m[temp],b,ans,m,n,i-1,j);
    dfs(root->m[temp],b,ans,m,n,i,j+1);
    dfs(root->m[temp],b,ans,m,n,i,j-1);
    b[i][j]=temp;
    };
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie(words);
        int m=board.size(),n=board[0].size();
        vector<string> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(root,board,ans,m,n,i,j);
            };
        };
        unordered_set<string> temp(ans.begin(),ans.end());
        ans.clear();
        for(string i:temp)ans.push_back(i);
        return ans;
    }
};
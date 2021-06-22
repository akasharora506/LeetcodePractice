class Trie{
    public:
    Trie* child[2];
    int c;
    Trie(){
        child[0]=child[1]=NULL;
        c=0;
    }
    void insert(Trie* root,int n){
        for(int i=31;i>=0;i--){
            bool x=n & (1<<i);
            if(!root->child[x])root->child[x]=new Trie();
            root->child[x]->c+=1;
            root=root->child[x];
        };
    }
    int search(Trie* root,int n,int k){
        int ans=0;
        for(int i=31;i>=0&&root;i--){
            bool x=n&(1<<i);
            bool y=k&(1<<i);   
            if(y){
                if(root->child[x]){
                    ans+=root->child[x]->c;
                };
                root=root->child[1-x];
            }else{
                root=root->child[x];
            };
        };
        return ans;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* root=new Trie();
        int ans=0;
        for(int i:nums){
            ans+=(root->search(root,i,high+1)-root->search(root,i,low));
            root->insert(root,i);
        };
        return ans;
    }
};
struct Trie{
    Trie* left;
    Trie* right;
};
void insert(Trie* root,int n){
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b){
            if(!root->right)root->right=new Trie();
            root=root->right;
        }else{
            if(!root->left)root->left=new Trie();
            root=root->left;
        };
    };
}
int find(Trie* root,int n){
    int ans=0;
    for(int i=31;i>=0&&root;i--){
        int b=(n>>i)&1;
        if((b&&root->left)||(!b&&root->right)){
            ans+=(1<<i);
            if(b)root=root->left;
            else root=root->right;
        }else{
            if(b)root=root->right;
            else root=root->left;
        };
    };
    return ans;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root= new Trie();   
        int ans=INT_MIN;
        for(int i:nums){
            int temp=find(root,i);
            ans=max(ans,temp);
            insert(root,i);
        };
        return ans;
    }
};
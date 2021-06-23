bool isPal(string word,int i){
    int j=word.length()-1;
    while(word[i]==word[j]&&i<j)i++,j--;
    return i>=j;
};
class Trie{
    public:
    unordered_map<char,Trie*> m;
    int id=-1;
    bool wordEnd=false;
    vector<int> pals;
    Trie(){}
    void insert(string word,int index){
        auto root=this;
        int n=word.length();
        reverse(word.begin(),word.end());
        for(int j=0;j<n;j++){
            char i=word[j];
            if(!root->m[i])root->m[i]=new Trie();
            if(isPal(word,j))root->pals.push_back(index);
            root=root->m[i];
        };
        root->id=index;
        root->pals.push_back(index);
        wordEnd=true;
    }
    void search(string word,int index,vector<vector<int>> &ans){
        auto root=this;
        for(int j=0;j<word.length();j++){
            char i=word[j];
            if(root->id>=0&&root->id!=index&&isPal(word,j)){
                ans.push_back({index,root->id});
            };
            if(!root->m[i])return;
            root=root->m[i];
        };
        for(int i:root->pals){
            if(i==index)continue;
            ans.push_back({index,i});
        };
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        Trie* root=new Trie();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            string curr=words[i];
            root->insert(curr,i);
        };
        for(int i=0;i<n;i++){
            string curr=words[i];
            root->search(curr,i,ans);
        };

        return ans;
    }
};
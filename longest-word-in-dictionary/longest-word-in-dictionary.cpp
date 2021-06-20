class Trie{
  public:
    unordered_map<char,Trie*> m;
    bool wordEnd=false;
    Trie(){}
    void insert(string w){
        auto root=this;
        for(char i:w){
            if(!root->m[i])root->m[i]=new Trie();
            root=root->m[i];
        };
        root->wordEnd=true;
    }
    bool find(string w){
        auto root=this;
        for(char i:w){
            if(!root->m[i]||!root->m[i]->wordEnd)return false;
            root=root->m[i];
        };
        return true;
    };
};
class Solution {
public:
    static bool comp(string &a,string &b){
        return a.length()==b.length()?a>b:a.length()<b.length();
    }
    string longestWord(vector<string>& w) {
        Trie* root=new Trie();
        sort(w.begin(),w.end(),comp);
        string ans;
        for(string word: w){
            if(root->find(word.substr(0,word.length()-1))){
                ans=word;
            };
            root->insert(word);
        };
        return ans;
    }
};
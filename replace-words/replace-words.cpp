class Trie{
    public:
    unordered_map<char,Trie*> m;
    bool isRoot=0;
    Trie(){}
    void insert(string root){
        auto curr=this;
        for(char i:root){
            if(!curr->m[i])curr->m[i]=new Trie();
            curr=curr->m[i];
        };
        curr->isRoot=true;
    };
    string getRoot(string s){
        string root;
        auto curr=this;
        for(char i:s){
            if(!curr->m[i])return s;
            root+=i;
            curr=curr->m[i];
            if(curr->isRoot)return root;
        };
        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* dict=new Trie();
        for(string i:dictionary){
            dict->insert(i);
        };
        vector<string> v;
        istringstream ss(sentence);
        string word;
        while(ss>>word){
            v.push_back(word);
        };
        string ans;
        for(string i:v){
            ans+=dict->getRoot(i)+" ";
        };
        ans.pop_back();
        return ans;
    }
};
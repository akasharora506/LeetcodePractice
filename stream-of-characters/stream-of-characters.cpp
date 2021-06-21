class Trie{
    public:
    unordered_map<char,Trie*> m;
    bool wordEnd=false;
    Trie(){};
    void insert(string w){
        reverse(w.begin(),w.end());
        auto root=this;
        for(char i:w){
            if(!root->m[i])root->m[i]=new Trie();
            root=root->m[i];
        };
        root->wordEnd=true;
    }
    bool search(string query){
        auto root=this;
        for(char i:query){
            if(root->wordEnd)return true;
            if(!root->m[i])return false;
            root=root->m[i];
        };
        return root->wordEnd;
    };
};
class StreamChecker {
public:
    string curr;
    int max_len=INT_MIN;
    Trie *root;
    StreamChecker(vector<string>& words) {
        root=new Trie();
        for(string word:words){
            root->insert(word);
            max_len=max(max_len,(int)word.length());
        };
    }
    
    bool query(char letter) {
        curr=letter+curr;
        if(curr.length()>max_len)curr.pop_back();
        return root->search(curr);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
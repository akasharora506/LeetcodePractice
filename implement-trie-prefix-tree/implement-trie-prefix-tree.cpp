class Trie {
public:
    /** Initialize your data structure here. */
    unordered_map<char,Trie*> m;
    bool wordEnd=0;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr=this;
        for(char i:word){
            if(!curr->m[i]){
                curr->m[i]=new Trie();
            };
            curr=curr->m[i];
        };
        curr->wordEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr=this;
        for(char i:word){
            if(!curr)return false;
            curr=curr->m[i];
        };
        return curr&&curr->wordEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr=this;
        for(char i:prefix){
            if(!curr)return false;
            curr=curr->m[i];
        };
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
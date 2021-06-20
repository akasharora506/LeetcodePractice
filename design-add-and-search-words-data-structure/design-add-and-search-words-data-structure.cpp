class WordDictionary {
public:
    unordered_map<char,WordDictionary*> m;
    bool wordEnd=false;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        auto curr=this;
        for(char i:word){
            if(!curr->m[i])curr->m[i]=new WordDictionary();
            curr=curr->m[i];
        };
        curr->wordEnd=true;
    }
    bool searchHelp(WordDictionary* root,string word,int j=0) {
        char i=word[j];
        if(!root)return false;
        if(j==word.length())return root && root->wordEnd;
        if(i=='.'){
            bool flag= false;
            for(auto i:root->m){
                flag=flag||searchHelp(i.second,word,j+1);  
            };
            return flag;
        }else{
            if(!root->m[i])return false;
            return searchHelp(root->m[i],word,j+1);
        };
    }
    bool search(string word) {
        auto curr=this;
        return searchHelp(curr,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
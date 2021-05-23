class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)
            return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> s(wordList.begin(),wordList.end());
        unordered_map<string,int> m;
        for(string word:wordList){
            m[word]=INT_MAX-1;
        };
        m[beginWord]=1;
        s.erase(beginWord);
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(int i=0;i<curr.length();i++){
                char oc=curr[i];
                string newWord=curr;
                for(char j='a';j<='z';j++){
                    if(oc==j)
                        continue;
                    newWord[i]=j;
                    if(s.find(newWord)!=s.end()){
                        m[newWord]=m[curr]+1;
                        q.push(newWord);
                        s.erase(newWord);
                    };
                };
                
            };
        };
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
        };
        if(m[endWord]==INT_MAX-1)
            m[endWord]=0;
        return m[endWord];
    }
};
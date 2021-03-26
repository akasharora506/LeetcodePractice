class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> req(26,0);
        for(string word:B){
            vector<int> temp(26,0);
            for(char i:word){
                temp[i-'a']++;
            };
            for(int i=0;i<26;i++){
                req[i]=max(req[i],temp[i]);
            };
        };
        vector<string> ans;
        for(string word:A){
            vector<int> temp(26,0);
            for(char i:word){
                temp[i-'a']++;
            };
            bool flag=1;
            for(int i=0;i<26;i++){
                if(temp[i]<req[i])
                    flag=0;
            };
            if(flag){
                ans.push_back(word);
            };
        };
        return ans;
    }
};
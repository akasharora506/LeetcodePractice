class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            for(int j=1;j<words[i].length();j++){
                s.erase(words[i].substr(j,words[i].length()-j));
            };   
        };
        int ans=0;
        for(string i:s){
            ans+=(i.length()+1);
        };
        return ans;
    }
};
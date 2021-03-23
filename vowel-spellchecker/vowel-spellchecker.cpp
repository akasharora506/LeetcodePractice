class Solution {
public:
    bool isVowel(char i){
        return (i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='A'||i=='E'||i=='I'||i=='O'||i=='U');
    };
    string toLowerCase(string a){
        string ans;
        for(char i:a){
            ans+=tolower(i);
        };
        return ans;
    }
    string devow(string a){
        string ans;
        for(char i:a){
            ans+=(isVowel(i)?'*':i);
        };
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_map<string,string> exact, cap, devowel;
        for(string word: wordlist){
            exact[word]=word;
            string low=toLowerCase(word);
            if(cap.find(low)==cap.end())cap[low]=word;
            string dev=devow(low);
          if(devowel.find(dev)==devowel.end())devowel[dev]=word;
        };
        for(string check:queries){
            if(exact.find(check)!=exact.end()){
                ans.push_back(exact[check]);
            }else if(cap.find(toLowerCase(check))!=cap.end()){
                ans.push_back(cap[toLowerCase(check)]);
            }else if(devowel.find(devow(toLowerCase(check)))!=devowel.end()){
                ans.push_back(devowel[devow(toLowerCase(check))]);
            }else{
                ans.push_back("");
            };
        };
        return ans;
    }
};

class Solution {
public:
    static bool comp(string &a,string &b){
        return a.length()<b.length();
    }
    bool canForm(string w,unordered_set<string> &dict){
        int n=w.length();
        if(dict.count(w))return true;
        for(int i=1;i<n;i++){
            if(dict.count(w.substr(0,i))&&canForm(w.substr(i,n-i),dict))
                return true;
        };
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        if(!w.size())return {};
        int n=w.size();
        sort(w.begin(),w.end(),comp);
        int ml=w[0].length();
        unordered_set<string> dict;
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(canForm(w[i],dict)){
                ans.push_back(w[i]);
            };
            dict.insert(w[i]);
        };
        return ans;
    }
};
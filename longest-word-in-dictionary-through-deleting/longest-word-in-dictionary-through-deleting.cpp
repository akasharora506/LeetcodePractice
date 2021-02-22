class Solution {
public:
    static bool comp(string &a,string &b){
        if(a.length()==b.length()){
            return a<b;
        };
        return a.length()>b.length();
    }

    bool isPossible(string start,string target){
        int count=0;
        for(int i=0;i<start.length();i++){
            if(start[i]==target[count]){
                count++;
            };
        };
        return count==target.length();
    };
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),comp);
        for(string i:d){
            if(isPossible(s,i))
                return i;
        };
        return "";
    }
};
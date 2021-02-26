class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(char i: s){
            m[i]++;
        };
        for(char i:t){
            m[i]--;
        };
        for(auto i: m){
            if(i.second!=0)
                return 0;
        };
        return 1;
    }
};
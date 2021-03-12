class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())
            return false;
        unordered_set<string> hash;
        for(int i=0;i<=s.length()-k;i++){
            string curr=s.substr(i,k);
            hash.insert(curr);
        };
        return hash.size()==pow(2,k);
    }
};
class Solution {
public:
    int numJewelsInStones(string j, string stones) {
        unordered_set<char> jewels(j.begin(),j.end());
        int ans=0;
        for(char i:stones){
            ans+=jewels.count(i);
        };
        return ans;
    }
};
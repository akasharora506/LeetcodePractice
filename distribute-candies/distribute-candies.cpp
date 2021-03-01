class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // unordered_set<int> s;
        bitset<200002> s;
        for(int i:candyType) s.set(i+100000);
        return min(s.count(),candyType.size()/2);
    }
};
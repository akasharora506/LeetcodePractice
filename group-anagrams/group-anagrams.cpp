class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> temp;
        for(string i: strs){
            string copy=i;
            sort(copy.begin(),copy.end());
            temp[copy].push_back(i);
        };
        for(auto i:temp){
            ans.push_back(i.second);
        };
        return ans;
    }
};
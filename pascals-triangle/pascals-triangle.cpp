class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={{1}};
        for(int i=2;i<=numRows;i++){
            vector<int> &prev=ans[i-2];
            vector<int> temp={1};
            for(int j=0;j<i-2;j++){
                temp.push_back(prev[j]+prev[j+1]);
            };
            temp.push_back(1);
            ans.push_back(temp);
        };
    return ans;
    }
};
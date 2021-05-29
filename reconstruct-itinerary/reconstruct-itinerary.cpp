class Solution {
public:
    static bool cmpr(vector<string> &a,vector<string> &b){
        return a[1]<b[1];
    }
    void dfs(unordered_map<string,multiset<string>> &m,vector<string> &ans,string curr="JFK"){
        if(m.count(curr)){
            while(!m[curr].empty()){
                auto nbr=m[curr].begin();
                string n=*nbr;
                m[curr].erase(nbr);
                dfs(m,ans,n);
            };
        };
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        sort(t.begin(),t.end(),cmpr);
        unordered_map<string,multiset<string>> m;
        vector<string> ans;
        for(auto i:t){
            string a=i[0],b=i[1];
            m[a].insert(b);
        };
        dfs(m,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
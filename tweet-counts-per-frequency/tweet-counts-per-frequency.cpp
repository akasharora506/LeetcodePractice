class TweetCounts {
public:
    unordered_map<string,multiset<int>> m;
    TweetCounts() {
        
    }
    
    void recordTweet(string s, int t) {
        m[s].insert(t);
    }
    
    vector<int> getTweetCountsPerFrequency(string f, string s, int st, int et) {
        int d=60*60*24;
        if(f[0]=='m')d=60;
        if(f[0]=='h')d=60*60;
        auto curr=m.find(s);
        vector<int> v((et-st)/d+1);
        if(curr!=m.end()){
            for(auto i=curr->second.lower_bound(st);i!=curr->second.end()&&*i<=et;i++){
                v[(*i-st)/d]++;
            };
        };
        return v;
    }
};

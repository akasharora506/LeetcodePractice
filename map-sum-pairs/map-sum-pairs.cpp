class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<char,MapSum*> m;
    int val=0;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto curr=this;
        for(char i:key){
            if(!curr->m[i]){
                curr->m[i]=new MapSum();
            };
            curr=curr->m[i];
        };
        curr->val=val;
    }
    int dfs(MapSum* curr){
        if(!curr)return 0;
        int ans=curr->val;
        for(auto i:curr->m){
            ans+=dfs(i.second);
        };
        return ans;
    };
    int sum(string prefix) {
        auto curr=this;
        for(char i:prefix){
            if(!curr->m[i]){
                return 0;
            };
            curr=curr->m[i];
        };
        return dfs(curr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
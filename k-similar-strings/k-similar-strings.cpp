class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if(s1==s2)
            return 0;
        int n=s1.length();
        queue<pair<string,pair<int,int>>> q;
        unordered_set<string> v;
        q.push({s1,{0,0}});
        v.insert(s1);
        while(!q.empty()){
            auto cur=q.front();
            string curr=cur.first;
            int swaps=cur.second.second;
            if(curr==s2)
                return swaps;
            q.pop();
            v.insert(curr);
            int idx=cur.second.first;
            while(s2[idx]==curr[idx])idx++;
            for(int i=idx+1;i<n;i++){
                if(curr[i]==s2[idx]){
                    swap(curr[i],curr[idx]);
                    if(v.find(curr)==v.end())q.push({curr,{idx+1,swaps+1}});
                    swap(curr[i],curr[idx]);
                };
            };
        };
        return -1;
    }
};
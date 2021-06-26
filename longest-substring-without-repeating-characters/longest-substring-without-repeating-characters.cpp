class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i=0,j=0;
        int ans=0;
        while(j<s.length()){
            if(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }else{
                st.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            };
        };
        return ans;
    }
};
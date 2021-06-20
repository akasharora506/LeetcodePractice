// class Trie{
//     public:
//     unordered_map<char,Trie*> m;
//     Trie(){}
//     void insert(string s){
//         auto curr=this;
//         for(char i:s){
//             if(!curr->m[i])curr->m[i]=new Trie();
//             curr=curr->m[i];
//         };
//     };
// };
class Solution {
public:
    int countSubstrings(string s, string t) {
     int m=s.length(),n=t.length(),ans=0;
        for(int ss=0;ss<m;ss++){
            for(int st=0;st<n;st++){
                int i=ss,j=st,d=0;
                while(i<m&&j<n){
                    if(s[i]!=t[j])d++;
                    if(d==1)ans++;
                    if(d>1)break;
                    i++,j++;
                };
            };
        };
        return ans;
    }
};
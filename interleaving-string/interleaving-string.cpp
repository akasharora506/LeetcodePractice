class Solution {
public:
    unordered_map<string,bool> m;
    bool help(string &s1,string &s2,string &s3,int l1,int l2,int l3,int i=0,int j=0,int k=0){
        if(k==l3)
            return i==l1&&j==l2;
        string key=to_string(i)+"*"+to_string(j)+"*"+to_string(k);
        if(m.count(key))
            return m[key];
        if(j==l2)
            return m[key]=s1[i]==s3[k]?s1.substr(i,l1-i)==s3.substr(k,l3-k):false;
        if(i==l1)
            return m[key]=s2[j]==s3[k]?s2.substr(j,l2-j)==s3.substr(k,l3-k):false;
        bool a=false,b=false;
        if(s1[i]==s3[k])
            a=help(s1,s2,s3,l1,l2,l3,i+1,j,k+1);
        if(s2[j]==s3[k])
            b=help(s1,s2,s3,l1,l2,l3,i,j+1,k+1);
        return m[key]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length(),l2=s2.length(),l3=s3.length();
        if(l3!=l1+l2)
            return false;
        return help(s1,s2,s3,l1,l2,l3);
    }
};
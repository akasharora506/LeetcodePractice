class Solution {
public:
    unordered_map<string,string> d;
    // Encodes a URL to a shortened URL.
    unordered_map<int,char> charSet;
    Solution(){
        for(int i=0;i<26;i++)
            charSet[i]=i+'a';
        for(int i=26;i<52;i++)
            charSet[i]=i-26+'A';
        for(int i=52;i<62;i++)
            charSet[i]=i-52+'0';
    }
    string generateRandomHash(){
        int hashLength=6;
        int len=charSet.size();
        string ans;
        while(hashLength--){
            int i=rand()%len;
            ans.push_back(charSet[i]);
        };
        return ans;
    }
    string encode(string longUrl) {
        string ans="http://tinyurl.com/"+generateRandomHash();
        d[ans]=longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return d[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
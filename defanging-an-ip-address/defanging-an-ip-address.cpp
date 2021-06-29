class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char i: address){
            if(i=='.')ans.push_back('[');
            ans.push_back(i);
            if(i=='.')ans.push_back(']');
        };
        return ans;
    }
};
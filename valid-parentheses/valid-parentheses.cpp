class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(char i:s){
            if(!t.empty()&&i==')'&&t.top()=='(')
                t.pop();
            else if(!t.empty()&&i=='}'&&t.top()=='{')
                t.pop();
            else if(!t.empty()&&i==']'&&t.top()=='[')
                t.pop();
            else
                t.push(i);
        };
        return t.empty();
    }
};
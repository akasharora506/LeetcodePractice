class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push=1,pop=0;
        stack<int> s;
        if(pushed.size())s.push(pushed[0]);
        int n=pushed.size();
        while(push<n||pop<n){
            if(!s.empty()&&s.top()==popped[pop]){
                s.pop();
                pop++;
            }else if(push!=n){
                s.push(pushed[push++]);
            }else
                return 0;
        };
        return s.empty();
    }
};
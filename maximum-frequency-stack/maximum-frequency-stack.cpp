class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxFreq;
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int x) {
        freq[x]++;
        if(freq[x]>maxFreq){
            maxFreq=freq[x];
        };
        m[freq[x]].push(x);

    }
    
    int pop() {
        int toRemove= m[maxFreq].top();
        m[maxFreq].pop();
        freq[toRemove]--;
        if(m[maxFreq].empty()){
            maxFreq--;
        };
        return toRemove;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
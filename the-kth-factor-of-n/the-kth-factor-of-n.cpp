class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> p;
        p.push(1);
        p.push(n);
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                int f1=i,f2=n/i;
                p.push(f1);
                if(f1!=f2)p.push(f2);
            };
        };
        while(p.size()>k)
                p.pop();
        return p.size()==k?p.top():-1;
    }
};
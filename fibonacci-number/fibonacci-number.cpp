class Solution {
public:
    int fib(int n) {
        // base case
        if(n==0||n==1)return n;
        // recall
        int a=fib(n-1),b=fib(n-2);
        // content
        return a+b;
    }
};

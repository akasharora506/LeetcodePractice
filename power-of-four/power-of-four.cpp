class Solution {
public:
    bool isPowerOfFour(float n) {
        // base case
        if(n<1.00) return false;
        if(n==1.00) return true;
        // recall
        bool ans= isPowerOfFour(n/4.00);
        // content
        return ans;
    }
};
// 4,5,6,7 divided by 4 == 1
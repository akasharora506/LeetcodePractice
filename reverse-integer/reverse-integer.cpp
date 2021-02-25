class Solution {
public:
     int reverse(int x) {
        int ans = 0, numb = abs(x);
    while (numb > 0) {
        if (INT32_MAX / 10 < ans) return 0;  // check overflow
        ans = ans * 10 + numb % 10;
        numb /= 10;
    }
    return x < 0 ? -ans : ans;
        
    }
};
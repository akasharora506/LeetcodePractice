class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        digits[i]+=1;
        int carry=digits[i]/10;
        digits[i]=digits[i]%10;
        i--;
        while(carry&&i>=0){
            int tot=digits[i]+carry;
            carry=tot/10;
            digits[i--]=tot%10;
        };
        if(carry){
            digits.insert(digits.begin(),carry);
        };
        return digits;
    }
};
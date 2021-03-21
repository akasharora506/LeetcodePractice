class Solution {
public:
    bool isPower2(vector<int> n){
        float num=0;
        if(n.front()==0)
            return false;
        for(int i:n){
            num*=10;
            num+=i;
        };
        if(ceil(log2(num))==floor(log2(num)))
            return true;
        return false;
    };
    bool reorderedPowerOf2(int N) {
        if(N==1)
            return true;
        vector<int> digits;
        while(N){
            digits.push_back(N%10);
            N/=10;
        };
        sort(digits.begin(),digits.end());
        do{
            if(isPower2(digits))
                return true;
        }while(next_permutation(digits.begin(),digits.end()));
        return false;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        bitset<5000001> sieve;
        for(long long i=2;i<=n;i++){
            for(long long j=i;j*i<=n;j++){
                sieve.set(j*i);
            };
        };
        long long ans=0;
        for(long long i=2;i<n;i++){
            ans+=(!sieve.test(i));
        };
        return ans;
        
    }
};
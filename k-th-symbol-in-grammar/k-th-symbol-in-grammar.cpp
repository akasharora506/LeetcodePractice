class Solution {
public:
    int kthGrammar(int n, int k) {
        //Base cases
        if(n == 1) return 0;
        if(n == 2){
            if(k == 1) return 0;
            else return 1;
        }
        
        //We will find the mid size, since by observing half of the pattern is similar to the previous value of n
        int mid = pow(2 , n - 1) / 2;
        

        if(k <= mid){
            //Since first half of the pattern was same so we just need to return the kth value from (n-1) th row
            return kthGrammar(n - 1 , k);
        }
        else{
            //This pattern has to emerge from [mid/2 ...sizeof(n)]
            int new_k = k - mid; //new_k is the index measured from mid
            
            if(new_k%2 == 0){
                //mid/2 + ceil(new_k*1.0/2) is the index of the bit in (n-1)th row from where our new_k index bit has been generated
                //if new_k is even and value at mid/2 + ceil(new_k*1.0/2) is 1 then we can observe the output 
                return kthGrammar(n - 1 , mid/2 + ceil(new_k*1.0/2)) == 1 ? 0 : 1;
            }
            else{
                //From previous explaination we can observer here the pattern
                return kthGrammar(n - 1 , mid/2 + ceil(new_k*1.0/2)) == 1 ? 1 : 0;
            }
        }
    }
};
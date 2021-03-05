class Solution {
public:
    vector<int> original,random;
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        bitset<200> b;
        int n=original.size();
        vector<int> random;
        while(b.count()!=n){
            int r=rand()%n;
            if(!b.test(r))random.push_back(original[r]);
            b.set(r);
        };
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
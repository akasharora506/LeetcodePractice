class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i=nums1.begin();
        auto j=nums2.begin();
        nums1.resize(m);
        while(i!=nums1.end()&&j!=nums2.end()){
            if(*j<*i){
                nums1.insert(i,*j);
                advance(j,1);
            };
            advance(i,1);
        };
        while(j!=nums2.end()){
            nums1.push_back(*j);
            advance(j,1);
        };
    }
};
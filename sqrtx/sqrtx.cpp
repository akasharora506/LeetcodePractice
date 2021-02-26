class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=x;
        int last=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid==x/mid){
                last=mid;
                break;
            }else if(mid<x/mid){
                last=mid;
                l=mid+1;
            }else{
                h=mid-1;
            };
        };
        return last;
    }
};
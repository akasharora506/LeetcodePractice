class Solution {
public:
    void mergeSort(vector<int> &v,vector<int> &c, vector<int> &in, int l,int r){
        if(l>=r)return;
        int mid=(r+l)/2;
        mergeSort(v,c,in,l,mid);
        mergeSort(v,c,in,mid+1,r);
        int start=l;
        int k=mid+1;
        int cnt=0;
        vector<int> curr;
        while(l<=mid&&k<=r){
            if(v[in[l]]<=v[in[k]]){
                curr.push_back(in[l]);
                c[in[l]]+=cnt;
                l++;
            }else{
                curr.push_back(in[k]);
                cnt++;
                k++;
            };
        };
        while(l<=mid){
            curr.push_back(in[l]);
            c[in[l++]]+=cnt;
        }
        while(k<=r){
            curr.push_back(in[k++]);
        }
        for(int i=start;i<=r;i++){
            in[i]=curr[i-start];
        };
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> in(n),count(n,0);
        for(int i=0;i<n;i++)in[i]=i;
        mergeSort(nums,count,in,0,n-1);
        return count;
    }
};
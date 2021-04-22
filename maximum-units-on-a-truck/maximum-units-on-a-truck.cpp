class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int i=0,ans=0;
        while(truckSize>0&&i<boxTypes.size()){
            if(boxTypes[i][0]>truckSize){
                ans+=truckSize*boxTypes[i][1];
                truckSize=0;
                i++;
                break;
            }else{
                ans+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
                i++;
            };
        };
        return ans;
    }
};
class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto comp = [&](int m,int n)-> bool {return abs(m-x)==abs(n-x)?m<n:abs(m-x)<abs(n-x);};
        sort(arr.begin(),arr.end(),comp);
        arr.resize(k);
        sort(arr.begin(),arr.end());
        return arr;
    }
};
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> h={{1,"I"},
                                   {4,"IV"},
                                   {5,"V"},
                                   {9,"IX"},
                                   {10,"X"},
                                   {40,"XL"},
                                   {50,"L"},
                                   {90,"XC"},
                                   {100,"C"},
                                   {400,"CD"},
                                   {500,"D"},
                                   {900,"CM"},
                                   {1000,"M"}};
        vector<int> check={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans;
        while(num){
            auto i=upper_bound(check.begin(),check.end(),num);
            advance(i,-1);
            ans+=h[*i];
            num-=*i;
        };
        return ans;
    }
};
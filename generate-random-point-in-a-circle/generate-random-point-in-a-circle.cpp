class Solution {
public:
    double r,x,y;
    double PI=2*cos(0.0);
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        vector<double> ans(2);
        double randomRadian=PI*((double)rand());
        double randomRadius=sqrt((double)rand()/RAND_MAX)*r;
        ans[0]=x+(randomRadius)*cos(randomRadian);
        ans[1]=y+(randomRadius)*sin(randomRadian);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
class MedianFinder {
public:
    int n;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        if(!right.empty() && num<right.top())left.push(num);
        else right.push(num);
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        };
        n++;
    }
    
    double findMedian() {
        if(n%2)return left.size()>right.size()?left.top():right.top();
        return ((double)left.top()+(double)right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
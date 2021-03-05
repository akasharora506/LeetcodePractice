class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<double> s;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        int n=s.size();
        auto i= s.begin();
        advance(i,(n+1)/2-1);
        if(n%2){
            return *i;
        }else{
            auto j=i;
            advance(j,1);
            return (*i+*j)/(double)2;
        };
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
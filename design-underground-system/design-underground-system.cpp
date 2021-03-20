class UndergroundSystem {
public:
    unordered_map<int,pair<string,double>> m;
    unordered_map<string,pair<double,double>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id].first=stationName;
        m[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string acc=m[id].first+stationName;
        avg[acc].second++;
        avg[acc].first=((avg[acc].first)*(avg[acc].second-1)+(double)t-m[id].second)/avg[acc].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avg[startStation+endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
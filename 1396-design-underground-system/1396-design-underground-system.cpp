class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<double, int>> travelTimes;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkIns[id].first;
        int checkInTime = checkIns[id].second;
        
        string key = startStation + "#" + stationName;
        double travelTime = t - checkInTime;
        
        travelTimes[key].first += travelTime;
        travelTimes[key].second++;
        
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "#" + endStation;
        double totalTime = travelTimes[key].first;
        int numTrips = travelTimes[key].second;
        
        return totalTime / numTrips;
    }
};


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
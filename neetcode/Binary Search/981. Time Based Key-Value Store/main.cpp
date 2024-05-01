class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back(make_pair(timestamp, value)); 
    }
    
    string get(string key, int timestamp) {       
        int l = 0, r = map[key].size()-1;
        string ret = "";
        while(r >= l) {
            int m = l + (r - l) / 2;

            if(map[key][m].first == timestamp) {
                return map[key][m].second;
            }

            if(timestamp < map[key][m].first) {
                r = m - 1;
            } else {
                ret = map[key][m].second;
                l = m + 1;
            }      
        }
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

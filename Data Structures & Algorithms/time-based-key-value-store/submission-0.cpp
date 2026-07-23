class TimeMap {
public:
    std::unordered_map<string, std::vector<std::pair<int,string>>> dataset;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dataset[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(dataset.count(key) == 0)
            return "";
        auto &vec =dataset[key];
        if(timestamp < vec[0].first) return "";
        int start = 0;
        int end = vec.size()-1;
        string res;
        while(start <=end){
            int mid = start +((end-start)>>1);
            if(vec[mid].first <= timestamp){
                res = vec[mid].second;
                start = mid+1;
            } else{
                end = mid-1;
            }
        }
        return res;
    }
};

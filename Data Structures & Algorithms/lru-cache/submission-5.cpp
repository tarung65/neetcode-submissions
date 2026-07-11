class LRUCache {
public:
    using Pi = std::pair<int,int> ;
    using ListPI =std::list<Pi>;
    using MapIntListItr = std::unordered_map<int, ListPI::iterator>;
    ListPI dll;
    MapIntListItr mp;
    int _capacity;
    LRUCache(int capacity) {
        _capacity = capacity;
        mp.reserve(capacity);
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        dll.splice(dll.begin(),dll,it->second);
        return it->second->second;
    }
    void remove(){
        mp.erase(dll.back().first);
        dll.pop_back();
    }
    void add(int key,int value){
        dll.push_front({key,value});
        mp[key] = dll.begin();
    }
    void put(int key, int value) {
        if(mp.count(key)){
            auto it = mp[key];
            dll.splice(dll.begin(),dll,it);
            it->second = value;
        }else {
            if(dll.size() == _capacity)
                remove();
            add(key,value);
        }
    }
};

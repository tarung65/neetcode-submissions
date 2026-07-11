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
    }
    
    int get(int key) {
        if(!mp.count(key))
            return -1;
        auto it = mp[key];
        dll.splice(dll.begin(),dll,it);
        return it->second;
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

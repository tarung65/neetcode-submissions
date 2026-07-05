class LRUCache {
public:
    std::list<std::pair<int,int>> dll;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> mp;
    int _capacity;
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)== mp.end()){
            return -1;
        }
        auto it = mp[key];
        dll.splice(dll.begin(),dll,it);
        return it->second;
    }
    void remove(int key){
       mp.erase(dll.back().first);
       dll.pop_back();
    }
    void add(int key,int value){
        dll.push_front({key,value});
        mp[key] = dll.begin();
    }
    void put(int key, int value) {
        if(mp.count(key)>0){
            auto it = mp[key];
            dll.splice(dll.begin(),dll,it);
            it->second = value;
        } else {
            if(dll.size() == _capacity)
                remove(key);
            add(key,value);
        }
    }
};

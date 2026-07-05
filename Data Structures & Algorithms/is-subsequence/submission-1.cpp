class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::unordered_map<char,std::queue<int>> char_map;
        for(int i = 0 ;i<t.size();i++){
            char_map[t[i]].push(i);
        }
        int current_index =-1;
        for(auto c : s){
            if(char_map.find(c)== char_map.end() ||char_map[c].empty())
                return false;
            int index = char_map[c].front();
            char_map[c].pop();
            while(index<current_index){
                if(char_map[c].empty()) return false;
                index = char_map[c].front();
                char_map[c].pop();
            }
            current_index = index;
        }
        return true;
    }
};
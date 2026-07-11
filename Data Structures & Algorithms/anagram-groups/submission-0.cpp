class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,std::vector<string>> group_map;
        auto stringtohash = [](string& str){
            string hash(26,0);
            for(char c : str){
                hash[c-'a']++;
            }
            return hash;
        };
        for(auto str : strs ){
            string hash = stringtohash(str);
            group_map[hash].push_back(str);
        }
        vector<vector<string>> result;
        for(auto [h,vec]:group_map){
            result.push_back(vec);
        }
        return result;
    }
};

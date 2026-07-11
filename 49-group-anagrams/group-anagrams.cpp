class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Use a 26-char string of counts as the key. No custom hash needed!
        std::unordered_map<string, vector<string>> map;
        
        for (const string& s : strs) {
            string countKey(26, 0); 
            for (char c : s) {
                countKey[c - 'a']++;
            }
            map[countKey].push_back(s);
        }
        
        vector<vector<string>> result;
        result.reserve(map.size()); // Optimization: reserve space upfront
        
        for (auto& pair : map) {
            result.push_back(std::move(pair.second)); // Moves efficiently via reference
        }
        
        return result;
    }
};
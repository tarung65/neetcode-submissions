class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> available;
        for(int i : nums){
            if(available.count(i)) return true;
            available.insert(i);
        }
        return false;
    }
};
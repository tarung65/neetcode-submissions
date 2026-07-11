class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0 ) return {};
        unordered_map<int,int>val_to_idx;
        for(int i =0 ;i<nums.size();i++){
            int rem = target-nums[i];
            if(val_to_idx.count(rem)){
                return {val_to_idx[rem],i};
            }
            val_to_idx[nums[i]] = i;
        }
        return {};
    }
};

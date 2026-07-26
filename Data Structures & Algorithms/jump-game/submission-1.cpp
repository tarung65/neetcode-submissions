class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t max_reach = 0;
        size_t n = nums.size();
        
        for (size_t i = 0; i < n; ++i) {
            // If current index is beyond the furthest reachable index, we're stuck
            if (i > max_reach) return false;
            
            max_reach = std::max(max_reach, i + static_cast<size_t>(nums[i]));
            
            // Early return if we can already reach or cross the destination
            if (max_reach >= n - 1) return true;
        }
        return false;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        size_t current_end = 0;
        size_t farthest = 0;

        // Note: loop stops at n - 1 because if we reach the last index, 
        // we don't need to jump again.
        for (size_t i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + static_cast<size_t>(nums[i]));

            // If we've reached the end of the current jump reach boundary
            if (i == current_end) {
                jumps++;
                current_end = farthest;

                // Early exit if we can already reach the end
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};

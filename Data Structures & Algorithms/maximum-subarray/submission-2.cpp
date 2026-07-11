class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max_sum = nums[0];
        int curr_sum =0;
        for (int num : nums) {
            curr_sum += num;
            max_sum = max(max_sum, curr_sum);
            // Reset if the running prefix sum drops below 0
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};

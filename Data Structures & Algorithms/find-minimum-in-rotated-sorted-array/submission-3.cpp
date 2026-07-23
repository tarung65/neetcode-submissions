static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMin(const vector<int>& nums) { // const reference prevents copy checks
        int start = 0;
        int end = nums.size() - 1;

        // Early return for arrays that aren't rotated or have 1 element
        if (nums[start] <= nums[end]) return nums[start];

        while (start < end) {
            int mid = start + ((end - start) >> 1); // bit shift for division
            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return nums[start];
    }
};
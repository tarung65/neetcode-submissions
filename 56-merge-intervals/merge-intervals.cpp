// This black magic unties C++ streams from C streams for maximum I/O speed
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sort strictly by the first element
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        result.reserve(intervals.size()); // Pre-allocates memory block
        
        // 2. Move instead of copying the first element
        result.push_back(std::move(intervals[0]));

        for (size_t i = 1; i < intervals.size(); ++i) {
            // Using a direct reference to avoid pointer chasing
            auto& last = result.back();
            
            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // 3. std::move transfers the vector inner pointers instead of copying data
                result.push_back(std::move(intervals[i]));
            }
        }

        return result;
    }
};
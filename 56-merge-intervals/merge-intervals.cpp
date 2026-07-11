class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Speed Optimization 1: Custom lambda lambda sort. 
        // Default sort compares the second element if the first elements match. 
        // We only care about the start times, which speeds up the sorting process.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        // Speed Optimization 2: Pre-allocate memory to avoid vector re-allocations
        result.reserve(intervals.size()); 
        
        result.push_back(intervals[0]);

        // Speed Optimization 3: Use a range-based reference loop to avoid indexing overhead
        for (const auto& interval : intervals) {
            // If it overlaps, extend the boundary of the last interval
            if (result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                // Otherwise, push it directly
                result.push_back(interval);
            }
        }

        return result;
    }
};
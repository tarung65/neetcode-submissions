class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t num = nums.size();
        std::vector<bool>visited(num,false);
        auto dfs = [&](auto& self, size_t i) -> void {
            if (i >= num || visited[i]) return;
            visited[i] = true;
            
            for (size_t j = 1; j <= nums[i]; ++j) {
                self(self, i + j);
            }
        };

        dfs(dfs, 0);
        return visited[num-1];
    }
};

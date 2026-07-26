class Solution {
public:
    int jump(vector<int>& nums) {
        size_t num = nums.size();
        std::vector<int>visited(num,num+1);
        visited[0] =0;
        auto dfs = [&](auto& self, size_t i) -> void {
            for (size_t j = 1; j <= nums[i]; ++j) {
                int next = i+j;
                if(next >= num) continue;
                if(visited[next] <= visited[i]+1) continue;
                visited[next] = visited[i]+1;
                self(self,next);
            }
        };

        dfs(dfs, 0);
        return visited[num-1];
    }
};

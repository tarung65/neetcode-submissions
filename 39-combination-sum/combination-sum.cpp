class Solution {
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int size = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        auto backtrack = [&](auto& self, int start, vector<int>& path, int remaining) -> void {
            if (remaining == 0) {
                res.push_back(path);
                return;
            }
            for (int i = start; i < size; i++) {
                if (remaining < candidates[i])
                    break;
                path.push_back(candidates[i]);
                self(self, i, path, remaining - candidates[i]);
                path.pop_back();
            }
        };
        backtrack(backtrack,0,path,target);
        return res;
    }
};
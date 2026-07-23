class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int start = 0;
        int end = ROWS*COLS - 1;
        auto getRC = [&](int index)->std::pair<int, int> {
            int r = index/COLS;
            int c = index%COLS;
            return {r,c};
        };
        while(start<=end){
            int index = (start+end)/2;
            auto [r,c] = getRC(index);
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) start = index+1;
            else end = index -1;
        }
        return false;
    }
};

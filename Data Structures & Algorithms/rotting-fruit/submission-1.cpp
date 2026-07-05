class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<std::pair<int,int>> q;
        int fresh = 0;
        for(int r =0;r<ROWS;r++){
            for(int c =0; c<COLS;c++){
                if(grid[r][c] == 2) q.push({r,c});
                else if (grid[r][c] == 1) fresh++;
            }
        }
        std::vector<std::pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int min =0;
        auto rotte = [&](int r,int c) -> bool {
            if(r<0 || c<0|| r>=ROWS || c>= COLS || grid[r][c] != 1)
                return false;
            grid[r][c] =2;
            q.push({r,c});
            fresh--;
            return true;
        };
        while(!q.empty()){
            int size = q.size();
            bool rotte_this_round = false;
            for(int i = 0;i<size;i++){
                auto [r,c] = q.front();q.pop();
                for(auto[dr,dc]:dirs){
                    if(rotte(r+dr,c+dc))
                        rotte_this_round = true;
                }
            }
            if(rotte_this_round)
                min++;
        }
        if(fresh)
            return -1;
        return min;
    }

};

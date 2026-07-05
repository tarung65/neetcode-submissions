class Solution {
public:
    struct PairHasher {
        std::size_t operator()(const std::pair<int, int>& p) const {
            // A simple hash combination technique (using a prime multiplier to reduce collisions)
            return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
        }
    };
    int orangesRotting(vector<vector<int>>& grid) {
        std::unordered_set<std::pair<int,int>,PairHasher> rotten;
        std::unordered_set<std::pair<int,int>,PairHasher> fresh;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r =0;r<ROWS;r++){
            for(int c =0;c<COLS;c++){
                if(grid[r][c] == 1)
                    fresh.insert({r,c});
                else if(grid[r][c] == 2)
                    rotten.insert({r,c});
            }
        }
        auto rotte = [&](int r,int c, std::unordered_set<std::pair<int,int>,PairHasher>& n_rotten)-> void {
            if(fresh.find({r,c}) != fresh.end()){
                n_rotten.insert({r,c});
                fresh.erase({r,c});
            }
        };
        int i =0;
        while(!fresh.empty()){
            std::unordered_set<std::pair<int,int>,PairHasher> n_rotten;
            for(auto it : rotten){
                int r = it.first;
                int c = it.second;
                rotte(r + 1, c, n_rotten); // Down
                rotte(r - 1, c, n_rotten);   // Up
                rotte(r, c + 1, n_rotten);   // Right
                rotte(r, c - 1, n_rotten);   // Left
            }
            if(n_rotten.empty())
                return -1;
            i++;
            rotten = n_rotten;
        }
        return i;
    }
};

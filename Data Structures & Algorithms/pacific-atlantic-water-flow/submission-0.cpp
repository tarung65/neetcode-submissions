class Solution {
public:
    constexpr static unsigned short pacific = 1;
    constexpr static unsigned short atlatic = 2;
    constexpr static unsigned short both = 3;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<unsigned short>> reachable(ROWS,vector<unsigned short>(COLS,0));
        stack<std::pair<int, int>> pacific_st;
        stack<std::pair<int, int>> atlantic_st;
        std::vector<vector<int>> both_available;
        vector<std::pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int i = 0;i<COLS;i++){
            reachable[0][i] |= pacific;
            pacific_st.push({0,i});
            reachable[ROWS-1][i] |= atlatic;
            atlantic_st.push({ROWS-1,i});
        }
        for(int i = 0;i<ROWS;i++){
            reachable[i][0] |= pacific;
            pacific_st.push({i,0});
            reachable[i][COLS-1] |= atlatic;
            atlantic_st.push({i,COLS-1});
        }
        while(!pacific_st.empty()){
            auto [r,c] = pacific_st.top();
            pacific_st.pop();
            int curr_h = heights[r][c];
            for(auto [dr,dc]: dirs){
                int n_r = r+dr;
                int n_c = c+dc;
                if(n_r<0 || n_c<0 || n_r>= ROWS || n_c>=COLS || heights[n_r][n_c]<curr_h || (reachable[n_r][n_c]&pacific))
                    continue;
                pacific_st.push({n_r,n_c});
                reachable[n_r][n_c] |=pacific;

            }

        }
        while(!atlantic_st.empty()){
            auto [r,c] = atlantic_st.top();
            atlantic_st.pop();
            int curr_h = heights[r][c];
            for(auto [dr,dc]: dirs){
                int n_r = r+dr;
                int n_c = c+dc;
                if(n_r<0 || n_c<0 || n_r>= ROWS || n_c>=COLS || heights[n_r][n_c]<curr_h || (reachable[n_r][n_c]&atlatic))
                    continue;
                atlantic_st.push({n_r,n_c});
                reachable[n_r][n_c] |=atlatic;

            }
        }
        for(int r=0;r<ROWS;r++){
            for(int c =0; c<COLS;c++){
                if(reachable[r][c] == both){
                    vector<int>loc({r,c});
                    both_available.push_back(loc);
                }
            }
        }
        return both_available;
    }
};

class Solution {
public:
    constexpr static unsigned int mask = 0xFFFF;
    void solve(vector<vector<char>>& board) {
        unsigned int ROWS = board.size();
        unsigned int COLS = board[0].size();
        std::unordered_set<unsigned int> required;
        std::queue<unsigned int> q;
        auto combine = [](unsigned int r, unsigned int c)->unsigned int {
            unsigned int m = r<<16;
            m |=c;
            return m;
        };
        auto decouple = [&](unsigned int combine)->std::pair<int,int> {
            unsigned int c = combine&mask;
            unsigned int r = (combine>>16)&mask;
            return std::pair<int,int>({r,c});
        };
        vector<std::pair<unsigned int,unsigned int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        auto validIndex = [&]( int r,int c)->bool{
            if(r<0 || r>=ROWS || c<0 || c>=COLS)
                return false;
            return true;
        };
        auto insertq = [&](unsigned int r, unsigned int c) ->void {
            unsigned int m = combine(r,c);
            q.push(m);
        };
        auto front = [&]()->std::pair<int,int> {
            unsigned int m = q.front();
            return decouple(m);
        };
        for(int i =0;i<ROWS;i++){
            if(board[i][0] == 'O'){
                unsigned int m = combine(i,0);
                required.insert(m);
                insertq(i,0);
            }
            if(board[i][COLS-1] == 'O'){
                unsigned int m = combine(i,COLS-1);
                required.insert(m);
                insertq(i,COLS-1);
            }
        }
        for(int i =0;i<COLS;i++){
            if(board[0][i] == 'O'){
                unsigned int m = combine(0,i);
                required.insert(m);
                insertq(0,i);
            }
            if(board[ROWS-1][i] == 'O'){
                unsigned int m = combine(ROWS-1,i);
                required.insert(m);
                insertq(ROWS-1,i);
            }
        }
        while(!q.empty()){
            auto [r,c] = front();
            q.pop();
            for(auto [dr,dc] : dirs){
                int n_r = r+dr;
                int n_c = c+dc;
                if(!validIndex(n_r,n_c))
                    continue;
                if(board[n_r][n_c] == 'O'){
                    unsigned int m = combine(n_r,n_c);
                    if(required.count(m))
                        continue;
                    required.insert(m);
                    insertq(n_r,n_c);
                }
            }
        }
        for(int r =0;r<ROWS;r++){
            for(int c =0;c<COLS;c++){
                if(board[r][c] == 'O'){
                    unsigned int m = combine(r,c);
                    if(!required.count(m)){
                        board[r][c] = 'X';
                    }
                }
            }
        }
    }
};
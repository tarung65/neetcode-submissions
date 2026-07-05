class Solution {
    int rows;
    int cols;
    int len;
    bool dfs(vector<vector<char>>& board, string& word,int r,int c,int i){
        if(r<0||c<0 || r>=rows || c >= cols || word[i] !=board[r][c])
            return false;
        if(i == len-1) return true;
        char temp = board[r][c];
        board[r][c] = '#';
        bool res = dfs(board,word,r+1,c,i+1)||
                    dfs(board,word,r-1,c,i+1)||
                    dfs(board,word,r,c+1,i+1)||
                    dfs(board,word,r,c-1,i+1);
        board[r][c] = temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        len = word.size();
        for(int i =0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(dfs(board,word,i,j,0))
                    return true;
        
        return false;
    }
};

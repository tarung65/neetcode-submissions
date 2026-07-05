class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max =0;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<int>>matrixi(ROWS,std::vector<int>(COLS,0));
        for(int r= 0;r<ROWS;r++){
            for(int c =0;c<COLS;c++)
                if(matrix[r][c] == '1')matrixi[r][c] =1;
        }
        auto value = [&](int r,int c)-> int{
            if(r<0 || c <0 )
                return 0;
            return (matrixi[r][c]);
        };
        auto setvalue = [&](int r,int c)->int{
            if(matrixi[r][c] == 1){
                matrixi[r][c] = 1 + std::min(value(r-1,c),std::min(value(r,c-1),value(r-1,c-1)));
            }
            return matrixi[r][c];
        };
        for(int r= 0;r<ROWS;r++){
            for(int c =0;c<COLS;c++){
                max = std::max(max,setvalue(r,c));
            }
        }
        return max*max;
    }
};
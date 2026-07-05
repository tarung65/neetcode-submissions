class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int cc = image[sr][sc];
        if(cc == color) return image;
        image[sr][sc] = color;
        if(sr-1>=0 && image[sr-1][sc] == cc)
            floodFill(image,sr-1,sc,color);
        if(sc-1>=0 && image[sr][sc-1] == cc)
            floodFill(image,sr,sc-1,color);
        if(sr+1 < rows  && image[sr+1][sc] == cc)
            floodFill(image,sr+1,sc,color);
        if(sc+1< cols && image[sr][sc+1] == cc)
            floodFill(image,sr,sc+1,color);
        return image;
    }
};
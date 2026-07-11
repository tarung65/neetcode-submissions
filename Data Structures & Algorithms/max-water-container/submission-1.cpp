class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st = 0;
        int en = heights.size()-1;
        int max_area = 0;
        while(st<en){
            int area = min(heights[st],heights[en])*(en-st);
            max_area = max(area,max_area);
            if(heights[st]< heights[en]){
                st++;
            } else {
                en--;
            }
        }
        return max_area;
    }
};

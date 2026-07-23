class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        for(int i : piles){
            right = max(i,right);
        }
        int left =1;

        auto ceildiv = [](int num,int div) ->int {
            int q = num/div;
            q = (num%div)?q+1:q;
            return q;
        };
        while(left < right){
            int hours = 0;
            int mid = (left+right)/2;
            for(int i : piles){
                hours += ceildiv(i,mid);
            }
            if(hours> h){
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

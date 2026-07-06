class Solution {
public:
    std::unordered_map<int,int> min_cost_map;

    void  find_min(vector<int>& coins, int amount){
        int min_cost = INT_MAX;
        for(int i : coins){
            int r = amount-i;
            if(r>=0  && min_cost_map.count(r)){
                min_cost = std::min(min_cost,1+min_cost_map[r]);
            }
        }
        if(min_cost != INT_MAX)
            min_cost_map[amount] = min_cost;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        min_cost_map[0] = 0;

        for(int i =1;i<=amount;i++){
            find_min(coins,i);
        }
        if(min_cost_map.count(amount))
            return min_cost_map[amount];
        return -1;
    }
};
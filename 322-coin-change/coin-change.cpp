class Solution {
public:
    

    void  find_min(vector<int>& coins, int amount, std::vector<int>& min_cost_map){
        for(int i : coins){
            int r = amount-i;
            if (r < 0)
                break; // Since coins are sorted, no subsequent coin will fit either!
            min_cost_map[amount] = std::min(min_cost_map[amount],1+min_cost_map[r]);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> min_cost_map(amount+1,amount+1);
        sort(coins.begin(),coins.end());
        min_cost_map[0] = 0;

        for(int i =1;i<=amount;i++){
            find_min(coins,i,min_cost_map);
        }
        if(min_cost_map[amount] == amount+1)
            return -1;
        return min_cost_map[amount];
    }
};
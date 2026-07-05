class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::vector<int>>> adj_list;
        adj_list.resize(n);
        std::vector<int>prices(n,INT_MAX);
        prices[src] =0;
        for(int i =0;i<=k;i++){
            std::unordered_map<int,int>update;
            for(auto f : flights){
                if(prices[f[0]] != INT_MAX){
                    int new_cost = prices[f[0]] + f[2];
                    if(prices[f[1]] > new_cost ){
                        if(update.find(f[1]) == update.end()){
                            update[f[1]] = new_cost;
                        } else {
                            update[f[1]] = std::min(update[f[1]],new_cost);
                        }
                    }
                }
            }
            for(auto dest_price : update)
                prices[dest_price.first] = dest_price.second;
        }
        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};

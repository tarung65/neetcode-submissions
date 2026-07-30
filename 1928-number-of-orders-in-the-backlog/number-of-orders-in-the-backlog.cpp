class Solution {
    using ORDER = std::pair<int,int>;
    std::priority_queue<ORDER> buyorder;
    std::priority_queue<ORDER,std::vector<ORDER>,std::greater<ORDER>> sellOrder;
    const int MOD = 1e9 + 7;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        for(auto& o: orders){
            if(o[2] == 0){ //buy order
                while(!sellOrder.empty() && std::get<0>(sellOrder.top()) <= o[0] && o[1] > 0){
                    auto [price, amount] = sellOrder.top();
                    sellOrder.pop();
                    if(amount <= o[1]){ //sell order is smaller than buy order
                        o[1] -= amount;
                    } else {//sell order is larger than buy order
                        amount -= o[1];
                        o[1] = 0;
                        sellOrder.push({price, amount});
                        break;
                    }
                }
                if(o[1] > 0) buyorder.push({o[0], o[1]});
            } else { //sell order
                while(!buyorder.empty() && std::get<0>(buyorder.top()) >= o[0] && o[1] > 0){
                    auto [price, amount] = buyorder.top();
                    buyorder.pop();
                    if(amount <= o[1]){ //buy order is smaller than sell order
                        o[1] -= amount;
                    } else {//buy order is larger than sell order
                        amount -= o[1];
                        o[1] = 0;
                        buyorder.push({price, amount});
                        break;
                    }
                }
                if(o[1] > 0) sellOrder.push({o[0], o[1]});
            }
        }
        long long backlog = 0;
        while(!buyorder.empty()){
            auto [price, amount] = buyorder.top();
            backlog += amount;
            buyorder.pop();
        }
        while(!sellOrder.empty()){
            auto [price, amount] = sellOrder.top();
            backlog += amount;
            sellOrder.pop();
        }
        return backlog % MOD;
    }
};
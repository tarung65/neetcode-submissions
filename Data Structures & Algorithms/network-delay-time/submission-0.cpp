class Solution {
    std::vector<std::vector<std::pair<int, int>>> adj_list;
    std::vector<int> weight;
    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > min_pq;
    std::unordered_set<int> unvisited;
    void parseEdges(vector<vector<int>>& times,int n){
        adj_list.resize(n);
        for(auto E : times){
            adj_list[E[0]-1].push_back({E[1]-1, E[2]});
        }
        weight.resize(n);
        for(int i=0;i<n;i++){
            weight[i] = INT_MAX;
            unvisited.insert(i);
        }

    }
    int FindShortesPath(int k){
        min_pq.push({0,k-1});
        weight[k-1] = 0;
        int max_delay =0;
        while(!min_pq.empty()){
            auto p = min_pq.top();
            min_pq.pop();
            int index = p.second;
            unvisited.erase(p.second);
            int current_dist = p.first;
            if (current_dist > weight[index]) continue;
            for(auto e : adj_list[index]){
                if (weight[index] + e.second < weight[e.first]){
                    weight[e.first] = weight[index]+ e.second;
                    min_pq.push({weight[e.first],e.first});
                }
            }
        }
        if(!unvisited.empty()){
            return -1;
        }
        for(int i = 0; i < weight.size(); i++) {
            max_delay = std::max(max_delay, weight[i]);
        }
        return max_delay;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        parseEdges(times,n);
        return FindShortesPath(k);
    }
};

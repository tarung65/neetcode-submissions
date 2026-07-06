class Solution {
    std::unordered_map<int,std::unordered_set<int>> nodes;
    std::unordered_map<int,int> bus_needed;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        int i=0;
        for(auto route : routes){
            for(int stop  : route){
                nodes[stop].insert(i);
                bus_needed[stop] = INT_MAX;
            }
            i++;
        }
        if(bus_needed.count(source) == 0 ||bus_needed.count(target) == 0 )
            return -1;
        bus_needed[source] = 0;
        std::queue<int> q;
        for(auto route: nodes[source]){
            q.push(route);
        }
        i =1;
        std::unordered_set<int>visited;
        std::unordered_set<int> route_visited;
        visited.insert(source);
        while(!q.empty()){
            int size = q.size();
            for(int j =0;j<size;j++){
                int route = q.front();
                route_visited.insert(route);
                q.pop();
                for(int stop : routes[route]){
                    if(visited.count(stop))
                        continue;
                    bus_needed[stop] = i;
                    visited.insert(stop);
                    for(int r :nodes[stop]){
                        if(!route_visited.count(r))
                            q.push(r);
                    }
                }

            }
            i++;
        }
        if(bus_needed[target] == INT_MAX)
            return -1;
        return bus_needed[target];
    }
};
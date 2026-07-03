class Solution {
    std::set<int>safe_nodes;
    std::unordered_set<int> cyclic_nodes;
    std::unordered_set<int>visited;
    bool findCyclic_node_i(vector<vector<int>>& graph,int i){
        if(safe_nodes.find(i) != safe_nodes.end())
            return false;
        if(cyclic_nodes.find(i) != cyclic_nodes.end()||visited.find(i) != visited.end()) return true;
        visited.insert(i);
        for(int j: graph[i]){
            if(findCyclic_node_i(graph,j)){
                cyclic_nodes.insert(j);
                return true;
            } else {
                safe_nodes.insert(j);
            }
        }
        return false;
    }
    void findsafe_node(vector<vector<int>>& graph){
        for(int i =0;i<graph.size();i++){
            visited.clear();
            if(!findCyclic_node_i(graph,i))
                safe_nodes.insert(i);
        }
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        findsafe_node(graph);
        vector<int> result;
        for(int i : safe_nodes)
            result.push_back(i);
        return result;
    }
};
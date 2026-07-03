
class Solution {
    std::vector<std::vector<int>>adj_list;
    std::vector<int>indeg;
public:
    void parse(int n, vector<vector<int>>& edges){
        adj_list.resize(n);
        indeg.resize(n);
        for(int i =0;i <edges.size();i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
            indeg[edges[i][1]]++;
            indeg[edges[i][0]]++;
        }
    }
    vector<int> findMHT(int n){
        std::unordered_set<int> left_nodes;
        std::queue<int> q[2];
        for(int i =0 ;i<n;i++){
            left_nodes.insert(i);
            if(indeg[i] == 1)
                q[0].push(i);
        }
        bool even = true;
        while(left_nodes.size()> 2){
            int q_select = even?0:1;
            int q_add = even?1:0;
            while(!q[q_select].empty()){
                int top = q[q_select].front();
                q[q_select].pop();
                left_nodes.erase(top);
                for(int i : adj_list[top]){
                    indeg[i]--;
                    if(indeg[i] == 1){
                        q[q_add].push(i);
                    }
                }
            }
            even = !even;
        }
        std::vector<int> result;
        for(int i :left_nodes)
            result.push_back(i);
        return result;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        parse(n,edges);
        return findMHT(n);
    }
};
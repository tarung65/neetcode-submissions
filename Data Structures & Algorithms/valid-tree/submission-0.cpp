class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        std::vector<std::unordered_set<int>> adjlist(n);
        auto set_edge = [&](int a,int b)->void {
            adjlist[a].insert(b);
            adjlist[b].insert(a);
        };
        for(int i =0;i<edges.size();i++){
            set_edge(edges[i][0],edges[i][1]);
        }
        std::unordered_set<int> visited;
        stack<int> st;
        st.push(0);
        visited.insert(0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(int next_node:adjlist[node]){
               if(visited.find(next_node) == visited.end()){
                    visited.insert(next_node);
                    st.push(next_node);
                }
            }
        };
        if(visited.size() == n)
            return true;
        return false;
    }
};

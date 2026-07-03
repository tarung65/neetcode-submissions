class Solution {
    bool isCyclic(int i,vector<vector<int>>& graph,vector<short>&state){
        if(state[i] !=0 )
            return state[i]==1;
        state[i] =1;
        for(int j :graph[i] ){
            if(isCyclic(j,graph,state)){
                return true;
            }
        }
        state[i] = 2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<short>state(n,0);
        vector<int>result;
        for(int i =0;i<n;i++){
            if(state[i] == 0){
                isCyclic(i,graph,state);
            }
        }
        for(int i =0;i<n;i++){
            if(state[i] == 2){
                result.push_back(i);
            }
        }
        return result;
    }
};
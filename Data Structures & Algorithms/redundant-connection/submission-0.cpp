class Solution {
public:
    std::vector<int> parent;
    void initialize(int n){
        parent.resize(n);
        for(int i =0 ;i<n;i++)
            parent[i] = i;
    }
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        int j = find(parent[i]);
        parent[i] = j;
        return j;
    }
    bool union_ab(int i ,int j){
        int a = find(i);
        int b = find(j);
        if(a==b) return true;
        else if(a<b) parent[b] = a;
        else parent[a] = b;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        initialize(edges.size()+1);
        for(auto e :edges){
            if(union_ab(e[0],e[1]))
                return e;
        }
        return vector<int>();
    }
};

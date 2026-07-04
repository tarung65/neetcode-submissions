class Solution {
public:
    std::vector<int> parent;
    void initialize(int n){
        parent.resize(n);
        for(int i =0;i<n;i++)
            parent[i] = i;
    }
    int find(int a){
        if(parent[a] == a)
            return a;
        int i = find(parent[a]);
        parent[a] = i;
        return  i;

    }
    void union_a_b(int a,int b){
        a = find(a);
        b = find(b);
        if(a<b)
            parent[b] = a;
        else
            parent[a] = b;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        initialize(n);
        for(auto v :edges ){
            union_a_b(v[0],v[1]);
        }
        std::unordered_set<int> roots;
        for(int i =0;i<n;i++){
            roots.insert(find(i));
        }
        return roots.size();
    }
};

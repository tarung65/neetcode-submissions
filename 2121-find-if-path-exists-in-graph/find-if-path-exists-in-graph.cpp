class Solution {
    class DSU{
        vector<int> parent;
        public:
        DSU(int n ){
            parent.resize(n);
            for(int i =0;i<n;i++)
                parent[i] = i;
        }
        int findParent(int i){
            if( i == parent[i])
                return i;
            int p = findParent(parent[i]);
            parent[i] =p;
            return p;
        }
        void Union(int i,int j){
            int a = findParent(i);
            int b = findParent(j);
            if(a<b)
                parent[b] =a;
            else
                parent[a] = b;
        }
    };
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU d(n);
        for(auto e : edges){
            d.Union(e[0],e[1]);
        }
        return (d.findParent(source)==d.findParent(destination));
    }
};
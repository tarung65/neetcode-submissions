class Solution {
    vector<int> parent;
    void init(int n){
        parent.resize(n);
        for(int i =0;i<n;i++)
            parent[i] = i;
    }
    int find(int i){
        if(parent[i] == i)
            return i;
        int j = find(parent[i]);
        parent[i] =j;
        return j;
    }
    void unionab(int i,int j){
        i = find(i);
        j = find(j);
        if(i <j)
            parent[j] = i;
        else
            parent[i] = j;
    }
    struct EDGE{
        int u;
        int v;
        int w;
        EDGE(int i,int j, int c){
            u = i;
            v = j;
            w = c;
        }
    };
    struct COMPAREE{
        bool operator ()(const EDGE& a,const EDGE& b)const {
            return a.w>b.w;
        }
    };
    int cost (vector<int>& p1,vector<int>& p2){
        return std::abs(p1[0]-p2[0]) + std::abs(p1[1]-p2[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        std::priority_queue<EDGE,std::vector<EDGE>,COMPAREE> minpq;
        for(int i =0;i<points.size()-1;i++){
            for(int j = i+1;j<points.size();j++){
                int c = cost(points[i],points[j]);
                EDGE e(i,j,c);
                minpq.push(e);
            }
        }
        int N = points.size();
        int total = 0;
        init(N);
        while(N>1){
            EDGE e = minpq.top();
            minpq.pop();
            if(find(e.u)!=find(e.v)){
                N--;
                total+= e.w;
                unionab(e.u,e.v);
            }
        }
        return total;
        
    }
};
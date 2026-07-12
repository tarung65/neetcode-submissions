class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>child(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto v: prerequisites){
            int p = v[1];
            int c = v[0];
            child[p].push_back(c);
            indeg[c]++;
        }
        stack<int>st;
        for(int i =0;i<numCourses;i++){
            if(indeg[i] == 0)st.push(i);
        }
        vector<int> res;
        while(!st.empty()){
            int p = st.top();
            st.pop();
            numCourses--;
            res.push_back(p);
            for(int c :child[p]){
                indeg[c]--;
                if(indeg[c] == 0) st.push(c);
            }
        }
        if(numCourses)
            return {};
        return res;
    }
};

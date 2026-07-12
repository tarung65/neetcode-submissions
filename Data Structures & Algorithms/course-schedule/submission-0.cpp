class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>>child(numCourses);
        std::vector<int>indeg(numCourses,0);
        for(auto v:prerequisites){
            int p = v[0];
            int c = v[1];
            child[p].push_back(c);
            indeg[c]++;
        }
        stack<int>st;
        for(int i =0;i<numCourses;i++){
            if(indeg[i] ==0) 
                st.push(i);
        }
        while(!st.empty()){
            int p = st.top();
            st.pop();
            numCourses--;
            for(int c : child[p]){
                indeg[c]--;
                if(indeg[c] == 0){
                    st.push(c);
                }
            }
        }
        return numCourses==0;
    }
};

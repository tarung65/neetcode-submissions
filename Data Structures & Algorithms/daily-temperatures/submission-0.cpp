class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int days = temperatures.size();
        std::vector<int>result(days,0);
        for(int i =0; i<days;i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

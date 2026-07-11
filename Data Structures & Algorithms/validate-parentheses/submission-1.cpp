class Solution {

    char closing_par(char c){
        if(c == '{') return '}';
        if(c == '(') return ')';
        if(c == '[') return ']';
        return 0;
    }
    bool isOpen_par(char c){
        if(c == '{' || c == '[' || c == '(') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(isOpen_par(c)){
                st.push(c);
                continue;
            } else if(st.empty() || c !=closing_par(st.top())){
                 return false;
            }
            st.pop();
        }

        return st.empty();
    }
};

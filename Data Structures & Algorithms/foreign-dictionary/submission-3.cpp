class Solution {
    std::unordered_map<char,std::unordered_set<char>>hasmap;
    std::unordered_map<char,int>indeg;
    bool parse_string(string& a,string b){
        int a_size = a.size();
        int b_size = b.size();
        int min = (a_size>b_size)?b_size:a_size;
        int max = (a_size>b_size)?a_size:b_size;
        bool to_check = true;
        for(int i =0;i <max;i++){
            if(i<a_size){
                if(indeg.find(a[i]) == indeg.end())
                    indeg[a[i]] = 0;
            }
            if(i<b_size){
                if(indeg.find(b[i]) == indeg.end())
                    indeg[b[i]] = 0;
            }
            if(i<min && to_check){
                char a_char = a[i];
                char b_char = b[i];
                if(a_char == b_char)
                    continue;
                if(hasmap[a_char].find(b_char) == hasmap[a_char].end()){
                    hasmap[a_char].insert(b_char);
                    indeg[b_char]++;
                }
                to_check = false;
            }
        }
        if(to_check && a_size > b_size)
            return false;
        return true;
    }
    bool parse(vector<string>& words){
        int n = words.size();
        for(int i =0;i<n-1;i++){
            bool ret = parse_string(words[i],words[i+1]);
            if(!ret)
                return ret;
        }
        return true;
    }
    std::string lexographical_order(){
        std::ostringstream ss;
        int size = indeg.size();
        stack<char>st;
        for(auto it : indeg){
            if(it.second == 0){
                st.push(it.first);
            }
        }
        int num =0;
        while(!st.empty()){
            char top = st.top();
            st.pop();
            num++;
            ss<<top;
            for(char c : hasmap[top]){
                indeg[c]--;
                if(indeg[c] == 0)
                    st.push(c);
            }
        }
        if(num == size)
            return ss.str();
        return string();
    }
public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1)
            return words[0];
        if(!parse(words)){
            return "";
        }
        return lexographical_order();
    }
};

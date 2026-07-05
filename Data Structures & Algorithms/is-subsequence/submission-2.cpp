class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0;
        int j =0;
        for(j = 0; j<s.size();j++){
            if(i >=t.size()) return false;
            while(s[j] != t[i++]){
                if(i>= t.size()) return false;
            }

        }
        return true;
    }
};
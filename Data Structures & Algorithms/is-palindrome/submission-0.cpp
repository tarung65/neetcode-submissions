class Solution {
public:
    bool isPalindrome(string s) {
        int st =0;
        int en = s.size()-1;
        auto isAlphaNum = [](char c){
            if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
                return true;
            return false;
        };
        while(st < en){
            char a = std::tolower(s[st]);
            char b = std::tolower(s[en]);
            if(!isAlphaNum(a)){
                st++;
                continue;
            }
            if(!isAlphaNum(b)){
                en--;
                continue;
            }
            if(a !=b) return false;
            st++;
            en--;
        }
        return true;
    }
};

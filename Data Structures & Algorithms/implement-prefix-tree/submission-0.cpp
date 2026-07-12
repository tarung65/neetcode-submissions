class TrieNode{
    vector<TrieNode*> childern;
    bool endOfWord;
    public:
        TrieNode():childern(26, nullptr), endOfWord(false){
        }
        bool isCharInTrie(char c){
            if(childern[c-'a'])
                return true;
            return false;
        }
        void insertChar(char c){
            childern[c-'a'] = new TrieNode();
        } 
        void markEndOfWord(){
            endOfWord = true;
        }
        bool isEndOfWord(){
            return endOfWord;
        }
        TrieNode* getChild(char c){
            return childern[c-'a'];
        }

};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c: word){
            if(!curr->isCharInTrie(c)){
                curr->insertChar(c);
            }
            curr = curr->getChild(c);
        }
        curr->markEndOfWord();
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c: word){
            if(!curr->isCharInTrie(c)){
                return false;
            }
            curr = curr->getChild(c);
        }
        return curr->isEndOfWord();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c: prefix){
            if(!curr->isCharInTrie(c)){
                return false;
            }
            curr = curr->getChild(c);
        }
        return true;
    }
};

class PrefixTree {
public:
    unordered_map<char, PrefixTree> branches;
    bool hasTerminator;

    PrefixTree() {
        this->branches = unordered_map<char, PrefixTree>();
        this->hasTerminator = false;
    }
    
    void insert(string word) {
        if (word.empty()) {
            hasTerminator = true;
            return;
        }
        char c = word[0];

        if (branches.find(c) == branches.end()) {
            branches[c] = PrefixTree();
        }
        branches[c].insert(word.substr(1));
    }
    
    bool search(string word) {
        if (word.empty()) {
            return hasTerminator;
        }
        char c = word[0];

        if (branches.find(c) == branches.end()) {
            return false;
        }
        
        return branches[c].search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if (prefix.empty()) return true;
        char c = prefix[0];

        if (branches.find(c) == branches.end()) {
            return false;
        }
        
        return branches[c].startsWith(prefix.substr(1));
    }
};

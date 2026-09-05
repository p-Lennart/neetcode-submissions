class WordDictionary {
public:
    vector<WordDictionary *> branches;
    // unordered_map<char, WordDictionary> branches;
    bool hasEOW;

    WordDictionary() {
        branches = vector<WordDictionary *>(30, nullptr);
        // branches = unordered_map<char, WordDictionary>();
        hasEOW = false;
    }
    
    void addWord(string word) {
        if (word.empty()) {
            hasEOW = true;
            return;
        }
        // char c = word[0];
        int c = word[0] - 'a';

        if (!branches[c]) branches[c] = new WordDictionary();

        // if (branches.find(c) == branches.end()) {
        //     branches[c] = WordDictionary();
        // }
        branches[c]->addWord(word.substr(1));
    }
    
    bool search(string word) {
        if (word.empty()) return hasEOW;
        // char c = word[0];
        int c = word[0] - 'a';

        if (word[0] == '.') {
            for (auto bPtr : branches) {
                if (!bPtr) continue;
                bool found = bPtr->search(word.substr(1));
                if (found) return true;
            }
        } else if (branches[c]) {
            bool found = branches[c]->search(word.substr(1));
            if (found) return true;
        }

        // if (c == '.') {
        //     for (pair<char, WordDictionary> b : branches) {
        //         bool found = b.second.search(word.substr(1));
        //         if (found) return true;
        //     }
        // } else if (branches.find(c) != branches.end()) {
        //     bool found = branches[c].search(word.substr(1));
        //     if (found) return true;
        // }

        return false;
    }
};

// Constraints analysis
// O(m * n * 4 * (3^(t-1)) + s)
// m*n: iterate over every cell
// 3^(t-1): scanning 3 cells while completing the rest of the word with length t?
class Solution {
    class TrieNode {
    public:
        unordered_map<char, TrieNode *> branches;
        bool hasEOW;

        TrieNode() {
            branches = unordered_map<char, TrieNode *>();
            hasEOW = false;
        }

        void insert(string &word) {
            TrieNode *curr = this;
            for (char c : word) {
                if (curr->branches.find(c) == curr->branches.end()) {
                    curr->branches[c] = new TrieNode();
                }
                curr = curr->branches[c];
            }
            curr->hasEOW = true;
        }

        TrieNode *branch(char c) {
            if (branches.find(c) == branches.end()) return nullptr;
            return branches[c];
        }
    };

    int m;
    int n;
    vector<vector<bool>> cellTaken;
    unordered_set<string> found;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode *wordTrie = new TrieNode();
        for (auto word : words) {
            wordTrie->insert(word);
        }
        
        m = board[0].size();
        n = board.size();
        
        cellTaken = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                string built = "";
                findWordAtCell(board, wordTrie, x, y, built);
            }
        }

        return vector(found.begin(), found.end());
    }
private:
    bool findWordAtCell(vector<vector<char>>& board, TrieNode *t, int x, int y, string &built) 
    {
        if (x < 0 || x >= m) return false;
        if (y < 0 || y >= n) return false;
        if (cellTaken[y][x]) return false;

        char c = board[y][x];

        TrieNode *tbranch = t->branch(c);
        if (!tbranch) return false;

        string oldBuild = built;
        built += c;
        cellTaken[y][x] = true;
        
        if (tbranch->hasEOW) found.insert(built);

        bool result = (
            findWordAtCell(board, tbranch, x+1, y, built) ||
            findWordAtCell(board, tbranch, x-1, y, built) ||
            findWordAtCell(board, tbranch, x, y+1, built) ||
            findWordAtCell(board, tbranch, x, y-1, built)
        );

        if (!result) {
            cellTaken[y][x] = false;
            built = oldBuild;
        }

        return result;
    }
};

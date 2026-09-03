class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> used;

        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[y].size(); x++) {
                pair<int, int> pos = { x, y };
                used.push_back(pos);
                bool res = existFrom(board, word, used);
                used.pop_back();
                if (res) return true;
            }
        }

        return false;
    }
private:
    bool existFrom(vector<vector<char>>& board, string word, vector<pair<int, int>> &used) {
        if (word.empty()) return true;
        char toMatch = word[0];
        
        pair<int, int> pos = used[used.size() - 1];
        if (board[pos.second][pos.first] != toMatch) return false;
        if (word.size() == 1) return true;

        vector<pair<int, int>> candidates;
        candidates.push_back({pos.first - 1, pos.second});
        candidates.push_back({pos.first + 1, pos.second});
        candidates.push_back({pos.first, pos.second - 1});
        candidates.push_back({pos.first, pos.second + 1});

        vector<pair<int, int>> moves;
        for (auto cpos : candidates) {
            if (cpos.first < 0 || cpos.second < 0) continue;
            if (cpos.first >= board[0].size() || cpos.second >= board.size()) continue;
            if (find(used.begin(), used.end(), cpos) != used.end()) continue;

            moves.push_back(cpos);
        }

        for (auto move : moves) {
            used.push_back(move);
            bool res = existFrom(board, word.substr(1), used);
            used.pop_back();
            if (res) return true;
        }

        return false;
    }
};

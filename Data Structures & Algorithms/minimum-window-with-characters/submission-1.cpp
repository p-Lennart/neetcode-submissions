class Solution {
public:
    bool updateLetter(char l, int delta, vector<int> &needed) {
        int key = l - 'A';
        if (key >= 0 && key < 'z' - 'A' + 1) {
            needed[key] += delta;
            return true;
        } else {
            return false;
        }
    }

    bool allSatisfied(vector<int> &needed) {
        for (int i : needed) if (i > 0) return false;
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> needed('z' - 'A' + 1, 0);
        for (char c : t) needed[c - 'A']++;

        int l = 0;
        int r = 0;

        int best_match_idx = -1;
        int best_match_len = s.size() + 1;

        while (r < s.size()) {
            // take R out
            updateLetter(s[r], -1, needed);

            while (allSatisfied(needed)) {
                int match_len = (r+1) - l;
                if (match_len < best_match_len) {
                    best_match_idx = l;
                    best_match_len = match_len;
                }

                // put L back
                updateLetter(s[l], 1, needed);
                l++;
            }
            r++;
        }

        if (best_match_idx == -1) return ""; 
        return s.substr(best_match_idx, best_match_len);
    }   
};

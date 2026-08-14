class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        int maxLen = 0;

        unordered_map<char, int> lastSeen;
        for (char c : s) lastSeen[c] = -1;

        while (r < s.length()) {
            char c = s[r];
            if (lastSeen[c] >= l) {
                maxLen = max(maxLen, r - l);
                l = lastSeen[c] + 1;
            }
            lastSeen[c] = r;
            r++;
        }
        maxLen = max(maxLen, r - l);
        return maxLen;
    }
};

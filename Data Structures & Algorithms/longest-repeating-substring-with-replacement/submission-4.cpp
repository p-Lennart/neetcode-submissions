class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        vector<int> alph(26, 0);

        int maxFreq = 0;
        int maxLen = 0;

        while (r < s.size()) {
            int keyR = s[r] - 'A';
            alph[keyR]++;
            maxFreq = max(maxFreq, alph[keyR]);

            int winLen = r - l + 1;
            while (winLen - maxFreq > k) {
                alph[s[l] - 'A']--;
                l++;
                winLen--;
            }

            maxLen = max(maxLen, winLen);
            r++;
        }

        return maxLen;
    }
};

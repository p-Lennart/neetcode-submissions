class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int pals = 0;
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                pals++;
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                pals++;
                l--;
                r++;
            }
        }

        return pals;
    }
};

class Solution {
private:
    int palRadFromIdxOdd(string &s, int idx) {
        int match_radius = -1;
        int l = idx;
        int r = idx;
        
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            match_radius++; // confirm radius of successful check
            l--; // set up for next check
            r++; // set up for next check
        }
        return match_radius;
    }

    int palRadFromIdxEven(string &s, int idx) {
        int match_radius = -1;
        int l = idx;
        int r = idx + 1;
        
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            match_radius++; // confirm radius of successful check
            l--; // set up for next check
            r++; // set up for next check
        }
        return match_radius;
    }


public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        
        string longest = "";

        for (int i = 0; i < s.size(); i++) {
            int palRad = palRadFromIdxOdd(s, i);
            int palLen = 1 + 2*palRad;
            // cout << "i " << i << " rad " << palRad << " len " << palLen << " start " << i - palRad << endl;
            if (palLen > longest.size()) longest = s.substr(i - palRad, palLen);

            palRad = palRadFromIdxEven(s, i);
            palLen = 2 + 2*palRad;
            // cout << "i " << i << " rad " << palRad << " len " << palLen << " start " << i - palRad << endl;
            if (palLen > longest.size()) longest = s.substr(i - palRad, palLen);
        }

        return longest;
    }
};

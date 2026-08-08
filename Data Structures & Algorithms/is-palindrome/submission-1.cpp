class Solution {
public:
    bool isPalindrome(string s) {
        size_t front = 0;
        size_t back = s.length() - 1;

        while (front < s.length() && back > 0) {
            if (!isAlphaNum(front, s) && front < back) {
                front++;
                continue;
            }
            if (!isAlphaNum(back, s) && back > front) {
                back--;
                continue;
            }

            if (back <= front) break; 

            if (toupper(s[front]) != toupper(s[back])) return false;
            
            cout << toupper(s[front]) << "|" << toupper(s[back]);

            front++;
            back--;
        }
        
        return true;
    }

    bool isAlphaNum(int idx, string s) {
        char c = s[idx];
        return (
            c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9'
        );
    }
};

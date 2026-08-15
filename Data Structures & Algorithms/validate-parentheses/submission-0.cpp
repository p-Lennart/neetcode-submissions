class Solution {
public:
    char rtl(char c) {
        if (c == ')') return '(';
        if (c == '}') return '{';
        if (c == ']') return '[';
    }
    bool isValid(string s) {
        stack<char> openParens;
        for (char c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (openParens.empty()) return false;
                if (openParens.top() != rtl(c)) return false;
                openParens.pop();
            } else {
                openParens.push(c);
            }
        }

        return openParens.empty();
    }
};

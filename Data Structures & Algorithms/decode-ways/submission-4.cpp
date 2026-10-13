class Solution {
private:
    int ndHelper(int pos, string &s, unordered_map<int, int> &helper) {
        if (helper.find(pos) != helper.end()) return helper[pos];
        // range: [1, 26]
        // recursive: at any point,
        // if digit > 2, only 1 way
        // if digit <= 2: two ways
        do {
            int size = s.size() - pos;
            if (size == 0) {
                helper[pos] = 1;
                break;
            }
            
            int digit = s[pos] - '0';
            if (digit == 0) {
                helper[pos] = 0;
                break;
            }

            if (digit > 2 || size == 1) {
                helper[pos] = ndHelper(pos+1, s, helper);
                break;
            }

            int digit2 = s[pos+1] - '0';       
            if (digit == 2 && digit2 > 6) {
                helper[pos] = ndHelper(pos+1, s, helper);
                break;
            }

            helper[pos] = ndHelper(pos+1, s, helper) + ndHelper(pos+2, s, helper);
        } while (false);

        return helper[pos];
    }
public:
    int numDecodings(string s) {
        if (s == "") return 0;
        unordered_map<int, int> helper;
        return ndHelper(0, s, helper);
    }
};

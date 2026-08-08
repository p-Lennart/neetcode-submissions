class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        
        vector<int> sizes;
        for (string& s : strs) {
            sizes.push_back(s.size());
        }

        string res = to_string(strs.size());
        res.append("#");

        for (string& s : strs) {
            res.append(to_string(s.size()));
            res.append("#");
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        size_t pos = s.find("#");
        
        if (pos == string::npos) {
            return vector<string>();
        }

        const int count = stoi(s.substr(0, pos));

        auto res = vector<string>(count);

        pos += 1;
        for (size_t i{}; i < count; i++) {
            size_t pos_r_size = s.find("#", pos);
            string size_str = s.substr(pos, pos_r_size - pos);
            const int sub_size = stoi(size_str);
            
            size_t pos_l_sub = pos_r_size + 1;
            res[i] = s.substr(pos_l_sub, sub_size);
            
            pos = pos_l_sub + sub_size;
        }

        return res;
    }
};

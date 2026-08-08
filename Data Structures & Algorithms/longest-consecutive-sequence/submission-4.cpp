class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        unordered_set<int> occ;
        for (size_t i{}; i < nums.size(); i++) {
            occ.insert(nums[i]);
        }

        unordered_map<int, size_t> seqs;
        int max_start = numeric_limits<int>::max();
        for (size_t i{}; i < nums.size(); i++) {
            int seq_prev = nums[i] - 1;

            if (occ.find(seq_prev) == occ.end()) {
                if (seqs.find(nums[i]) == seqs.end()) {
                    cout << "Spawn new root: " << nums[i] << "\n"; 
                    seqs[nums[i]] = 1;
                }
            } else {
                while (occ.find(seq_prev) != occ.end()) {
                    seq_prev -= 1;
                }

                cout << "Traced " << nums[i] << " down to " << (seq_prev + 1) << "\n";

                int len = nums[i] - seq_prev;
                if (len > seqs[seq_prev + 1]) {
                    seqs[seq_prev + 1] = len;
                }
            }
            
            int len = seqs[nums[i]];
            cout << "dist = " << len << "\n";

            if (max_start == numeric_limits<int>::max() || len > seqs[max_start]) {
                cout << "yes, " << len << " > " << seqs[max_start] << "\n"; 
                max_start = seq_prev + 1;
            }

            cout << "max_start = " << max_start << "\n";
            cout << "max = " << seqs[max_start] << "\n";
        } 

        return seqs[max_start];
    }
};

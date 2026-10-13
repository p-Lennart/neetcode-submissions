class Solution {
private:
    int ccHelper(unordered_map<int, int> &memo, vector<int>& coins, int amount) {
        if (memo.find(amount) != memo.end()) return memo[amount];
        if (amount == 0) return 0;
        
        int minUse = -1;
        int n = coins.size();
        
        for (int i = 0; i < n; i++) {
            int newAmt = amount - coins[i];
            if (newAmt < 0) continue; // overshoot
            int use = ccHelper(memo, coins, newAmt);
            if (use == -1) continue; // not makeable
            int newUse = 1 + use;
            if (newUse < minUse || minUse == -1) minUse = newUse;
        }

        memo[amount] = minUse;
        return minUse;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return ccHelper(memo, coins, amount);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // sliding window version
        int n = prices.size();
        int l = 0;
        int r = 1;

        // if r>l, then measure profit
        // if r<l, then r is a better l-point

        int bestProfit = 0;
        
        while (r < n) {
            int pr = prices[r];
            int pl = prices[l];

            if (prices[r] > prices[l]) {
                int profit = pr - pl;
                bestProfit = max(bestProfit, profit);
                r++;
            } else {
                l = r;
                r++;
            }
        }

        return bestProfit;
    }
};

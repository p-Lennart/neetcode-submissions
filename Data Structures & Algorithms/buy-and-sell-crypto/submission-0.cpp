class Solution {
public:
    int profit(vector<int>& prices, int a, int b) {
        return prices[b] - prices[a];
    }

    int maxProfit(vector<int>& prices) {
        // passage of time doesn't matter
        // buy low, sell high
        int n = prices.size();

        vector<int> maxFromI = prices;
        maxFromI[n-1] = prices[n-1];

        for (int i = n-2; i >= 0; i--) {
            maxFromI[i] = max(prices[i], maxFromI[i+1]);
        }
        
        vector<int> profits = prices;
        for (int i = 0; i < n; i++) profits[i] = maxFromI[i] - prices[i];

        return *max_element(profits.begin(), profits.end());
    }
};

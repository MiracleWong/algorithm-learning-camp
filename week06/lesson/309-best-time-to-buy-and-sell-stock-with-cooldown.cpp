class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return maxProfit(prices.size(), prices, 0);
    }
    int maxProfit(int c, vector<int> &prices, int fee)
    {
        int n = prices.size();
        // Move prices from [0..n-1] to [1..n]
        prices.insert(prices.begin(), 0);

        // Initialize DP array
        vector<vector<vector<vector<int> > > > f(n + 1, vector<vector<vector<int> > >(2, vector<vector<int> >(c + 1, vector<int>(2, -1000000000))));
        f[0][0][0][0] = 0;

        // DP
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= 1; j++)
                for (int k = 0; k <= c; k++)
                    for (int l = 0; l <= 1; l++)
                    {
                        if (j == 0 && k < c && l == 0)
                        {
                            f[i + 1][1][k + 1][0] = max(f[i + 1][1][k + 1][0], f[i][j][k][l] - prices[i + 1] - fee);
                        }
                        if (j == 1 && l == 0)
                        {
                            f[i + 1][0][k][1] = max(f[i + 1][0][k][1], f[i][j][k][l] + prices[i + 1]);
                        }
                        f[i + 1][j][k][0] = max(f[i + 1][j][k][0], f[i][j][k][l]);
                    }

        // Calculate the target
        int ans = 0;
        for (int k = 0; k <= c; k++)
            for (int l = 0; l <= 1; l++)
                ans = max(ans, f[n][0][k][l]);
        return ans;
    }
};
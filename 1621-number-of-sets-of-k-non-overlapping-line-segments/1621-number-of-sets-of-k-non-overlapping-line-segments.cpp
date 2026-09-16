using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<vector<ll>>> dp(n + 1,vector<vector<ll>>(k + 1, vector<ll>(2, -1)));

        function<ll(int, int, int)> solve = [&](int i, int j, int open) -> ll {
            if (j < 0)
                return 0;

            if (i == n)
                return (j == 0 && open == 0);

            if (dp[i][j][open] != -1)
                return dp[i][j][open];

            ll ans = 0;

            if (open) {
                ans += solve(i + 1, j, 1);
                ans += solve(i, j - 1, 0);
            } 
            else {
                ans += solve(i + 1, j, 0);

                ans += solve(i + 1, j, 1);
            }

            return dp[i][j][open] = ans % mod;
        };

        return solve(0, k, 0);
    }
};
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Solution {
public:
    int t[1001][10001];  // i, amount
    const int INF = 1e9;

    int solve(vector<int>& coins, int i, int amount) {
        // base cases
        if (amount == 0) return 0;
        if (i >= coins.size()) return INF;

        // memoization
        if (t[i][amount] != -1) return t[i][amount];

        int take = INF;

        
        if (coins[i] <= amount) {
            int res = solve(coins, i, amount - coins[i]);
            if (res != INF) {
                take = 1 + res;
            }
        }

        
        int skip = solve(coins, i + 1, amount);

        return t[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));

        int ans = solve(coins, 0, amount);

        return (ans >= INF) ? -1 : ans;
    }
};
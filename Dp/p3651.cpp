class Solution {
public:
    int dp[85][85][15] = {0};   //dp[i][j][s]表示经过s次传送操作后到达(i，j)的代价
    const int INF = 0X3F3F3F3F;

    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(); 
        int n = grid[0].size();
        memset(dp, 0x3f, sizeof(dp));
        //第0层
        int mx = grid[0][0];
        dp[0][0][0] = 0;

        for (int i = 1; i < m; i++) {
            mx = max(mx, grid[i][0]);
            dp[i][0][0] = dp[i-1][0][0] + grid[i][0];
        } //O(m)
        for (int j = 1; j < n; j++) {
            mx = max(mx, grid[0][j]);
            dp[0][j][0] = dp[0][j-1][0] + grid[0][j];
        } //O(n)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                mx = max(mx, grid[i][j]);
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + grid[i][j];
            }
        } //O(mn)
    
        // 第s层
        int ans = dp[m-1][n-1][0];
        for (int s = 1; s<=k; s++) {
            vector<int> sufmin(mx + 1, INF);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j<n; j++) {
                    sufmin[grid[i][j]] = min(sufmin[grid[i][j]], dp[i][j][s-1]);
                }
            }
            for (int v = mx - 1; v >= 0; v--) {
                sufmin[v] = min(sufmin[v+1], sufmin[v]);
            }
            //传送
            for (int i = 0; i< m; i++) {
                for (int j = 0; j< n; j++) {
                    dp[i][j][s] = sufmin[grid[i][j]];
                }
            }
            // 移动
            for (int i = 1; i<m; i++) {
                dp[i][0][s] = min(dp[i][0][s], dp[i-1][0][s] + grid[i][0]);
            }
            for (int j = 1; j<n; j++) {
                dp[0][j][s] = min(dp[0][j][s], dp[0][j-1][s] + grid[0][j]);
            }
            for (int i = 1; i<m; i++) {
                for (int j = 1; j<n ; j++) {
                    dp[i][j][s] = min(dp[i][j][s], min(dp[i-1][j][s], dp[i][j-1][s]) + grid[i][j]);
                }
            }
        }
        return dp[m-1][n-1][k];
    }
};
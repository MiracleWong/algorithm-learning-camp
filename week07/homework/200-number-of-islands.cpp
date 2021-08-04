class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n*m; i++) fa[i] = i;
        // 每条边代表一次合并
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int k = (m*i)+j+1;
                if (grid[i][j] == '1') { 
                    // unionSet(i, j);
                    if (i-1 >= 0 && grid[i-1][j] == '1' && find(k) != find(k-m)) fa[find(k)] = find(k-m);
                    if (j-1 >= 0 && grid[i][j-1] == '1' && find(k) != find(k-1)) fa[find(k)] = find(k-1);
                } else {
                    fa[k] = 0;
                }
            }
        // 有几棵树？（有几个根）
        int ans = 0;
        for (int i = 0; i < n * m; i++) {
            if (fa[i] == i) ans++;
        }
        return ans;

    }
private:
    void unionSet(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x != y) fa[x] = y;
    }

    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    int fa[300*300+1];
};
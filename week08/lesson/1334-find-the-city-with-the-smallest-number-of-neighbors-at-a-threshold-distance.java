class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // 邻接矩阵初值，i到i长度为0，没有变长度为INF，其余为输入的边
        int[][] d = new int[n][n];
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                d[i][j] = (int)1e9;
            }
            d[i][i] = 0;
        }
        for (int[] edge: edges) {
            int x = edge[0];
            int y = edge[1];
            int z = edge[2];
            // 无向图，所以d[x][y] 和 d[y][x] 都要增加
            d[x][y] = z;
            d[y][x] = z;
        }
        
        // Floyd 算法：O(n^3)
        // 动态规划的顺序：阶段，状态，决策
        for (int k = 0; k < n; k++)
            for (int i=0; i < n; i++)
                for (int j=0; j < n; j++)
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);



        // 返回结果
        int ansCount = n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i!=j && d[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= ansCount) {
                ansCount = count;
                ans = i;
            }
        }
        return ans;
    }
}
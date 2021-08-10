class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // dist 数组初始化，起点为0，其余点为+oo
        int[] dist = new int[n+1]; // 0~n
        for (int i = 1; i<=n; i++) dist[i] = (int)1e9;
        dist[k] = 0;
        // Bellman-ford 算法
        for (int round=1; round < n; round++) {
            boolean flag = false;
            for (int[] edge : times) {
                int x = edge[0];
                int y = edge[1];
                int z = edge[2];
                if (dist[x] + z < dist[y]) {
                    dist[y]= dist[x]+z;
                    flag = true;
                }
            }
            if (!flag) break;
        }

        // 统计答案，题目要求max(dist[i])
        int ans = 0;
        for (int i=1; i <= n; i++) {
            ans = Math.max(ans, dist[i]);
        }
        if (ans == 1e9) ans = -1;
        return ans;

    }
}
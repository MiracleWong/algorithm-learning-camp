class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 建立图
        vector<vector<int>> ver(n+1, vector<int>());
        vector<vector<int>> edge(n+1, vector<int>());
        for (auto& e: times) {
            int x = e[0], y = e[1], z = e[2];
            ver[x].push_back(y);
            edge[x].push_back(z);
        }

        vector<int> dist(n+1, 1e9);
        vector<bool> v(n+1, false); // expand是否扩展过
        dist[k] = 0;
        // dist 编号
        priority_queue<pair<int,int>> q;
        q.push(make_pair(-dist[k], k));

        // Dijkstra 算法
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (v[x]) continue;
            v[x] = true;
            for (int i = 0; i < ver[x].size(); i++) {
                int y = ver[x][i];
                int z = edge[x][i];
                if (dist[x] + z < dist[y]) {
                    dist[y] = dist[x] + z;
                    q.push(make_pair(-dist[y], y));
                }
            }
        }

        int ans = 0;
        for (int i=1; i <= n; i++) {
            cout << "dist[i]" << dist[i] << endl;
            ans = max(ans, dist[i]);
        }
        if (ans == 1e9) ans = -1;
        return ans;
    }
};
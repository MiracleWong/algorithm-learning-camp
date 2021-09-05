class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // {(x1,y1),...}
        // (-200, 30000)
        // string = "-200, 30000"
        // long long: (-200, 30000) 平移到 （-200 + 30000, 30000 + 30000）
        unordered_set<string> blockers;
        for (auto& obstacle : obstacles) {
            blockers.insert(calcHash(obstacle[0], obstacle[1]));
        }
        // 方向数组技巧
        //          N   E  S   W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x =0, y = 0;    // 面向北方
        int dir = 0;
        int ans = 0;
        for (int cmd : commands){
            if (cmd > 0) {
                for (int i = 0; i < cmd; i++){
                    int nextx = x + dx[dir];
                    int nexty = y + dy[dir];
                    // 有障碍物
                    if (blockers.find(calcHash(nextx, nexty)) != blockers.end()) {
                        break;
                    }
                    // 走一步
                    x = nextx;
                    y = nexty;
                    ans = max(ans, x*x + y*y);
                }
            } else if (cmd == -1) {
                // 右转（顺时针）
                dir = (dir + 1) % 4;
            } else {
                 // 左转（逆时针），为避免负数，加一个mod数
                dir = (dir - 1 + 4) % 4;
            }
        }
        return ans;

    }

private:
    string calcHash(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }
};
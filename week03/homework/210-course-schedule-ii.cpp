class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        // 出边数组初始化，建立n个空的list
        edges = vector<vector<int>>(n, vector<int>());
        inDeg = vector<int>(n,0);
        ans.reserve(n);
        for(vector<int>& pre: prerequisites){
            int ai= pre[0];
            int bi= pre[1];
            addEdge(bi,ai);
        }
        return topSort(n);
    }
private:
    // 拓扑排序函数,返回学习的课程数
    vector<int> topSort(int n){
        // 拓扑排序基于BFS，需要队列
        queue<int> q;

        // 从所有的零入点出发
        for (int i=0; i < n; i++)
            if (inDeg[i] == 0) q.push(i);

        // 执行BFS
        while(!q.empty()) {
            int x = q.front(); // 取队头（这门课程学习了）
            q.pop();
            ans.push_back(x);
            // 考虑所有的出边
            for (int y : edges[x]) {
                inDeg[y]--;
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        if(ans.size() < n) return {};
        return ans;
    }
    // 加边函数
    void addEdge(int x, int y) {
        edges[x].push_back(y);
        inDeg[y]++;
    }
    int n;
    // 出边数组存图
    vector<vector<int>> edges;
    // 入度数
    vector<int> inDeg;
    // 排序结果
    vector<int> ans;
};
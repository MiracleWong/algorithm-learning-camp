from typing import List

from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1
        self.m = len(grid)
        self.n = len(grid[0])
        self.visit = [[False] * self.n for i in range(self.m)]
        ans = 1
        dx = [-1, -1,  0,  1, 1, 1, 0, -1]
        dy = [ 0, -1, -1, -1, 0, 1, 1, 1]
        q = deque()
        # 第一步：push起点
        q.append([0, 0])
        self.visit[0][0] = True
        while len(q) > 0:
            now = q.popleft()
            x, y = now[0], now[1]
            print("x:" + str(x) + " y:" + str(y))
            # 扩展所有出边（8个方向）
            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                # 任何时候访问数组前，判断合法性
                if nx < 0 or ny < 0 or nx >= self.m or ny >= self.n:
                    continue
                if grid[nx][ny] == 0 and not self.visit[nx][ny]:
                    q.append([nx, ny])
                    # BFS：入队时标记visit
                    self.visit[nx][ny] = True
                    ans += 1
        return ans



if __name__ == '__main__':
    s = Solution()
    test_list = [
        ([[0,0,0],[1,1,0],[1,1,0]],4),
        ([[1,0,0],[1,1,0],[1,1,0]],-1),
    ]
    for test_index, test_case in enumerate(test_list, start=1):
        *test, result = test_case
        print(*test)
        test_result = s.shortestPathBinaryMatrix(*test)
        if test_result != result:
            raise ValueError("\n testcase %d error:\n expect: %s \n actually %s" % (test_index, result, test_result))
        print("test_case %d succeed." % test_index)
class Solution:
    # dp数组的含义：爬到第i阶的方案数
    # dp[1]=1, dp[2]=2
    # 转移方程：dp[i] = dp[i-1] + dp[i-2]
    # 含义：爬到第i阶的方案数 = 爬到第i-1阶的方案数（再爬1阶达楼顶） + 爬到第i-2阶的方案数（再爬2阶达楼顶）
    def climbStairs(self, n: int) -> int:
        if n < 3: return n
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n+1):
            # 爬到第i阶的方案数
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
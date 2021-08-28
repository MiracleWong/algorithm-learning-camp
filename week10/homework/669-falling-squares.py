#!/usr/bin/env python3
# -*- encoding: utf-8 -*- 
"""
@Author: MiracleWong
@Email: cfwr1991@126.com
@Time: 2021/8/25 23:43
@Software: PyCharm
@Project: leetcode-python
@File: 669-falling-squares.py
@Version: Python 3.83
"""

from typing import List

class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        m = set()
        for i in range(len(positions)):
            l, r = positions[i][0], positions[i][0] + positions[i][1] - 1
            m |= {l, r}
        m = sorted(list(m))
        index = {x: i for i, x in enumerate(m)}
        # print(index)
        a = [0] * len(index)
        ans = []
        flag = 0
        for l, length in positions:
            L = index[l]
            R = index[l + length - 1]
            x = max(a[L:R + 1])
            for i in range(L, R + 1):
                a[i] = x + length
            flag = max(flag, x + length)  
            ans.append(flag)
        # print(ans)
        return ans

if __name__ == '__main__':
    s = Solution()
    test_list = [
        ([[1, 2], [2, 3], [6, 1]],[2, 5, 5]),
    ]
    for test_index, test_case in enumerate(test_list, start=1):
        *test, result = test_case
        test_result = s.fallingSquares(*test)
        if test_result != result:
            raise ValueError("\n testcase %d error:\n expect: %s \n actually %s" % (test_index, result, test_result))
        print("test_case %d succeed." % test_index)

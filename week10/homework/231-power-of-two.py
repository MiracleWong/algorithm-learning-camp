#!/usr/bin/env python3
# -*- encoding: utf-8 -*- 
"""
@Author: MiracleWong
@Email: cfwr1991@126.com
@Time: 2021/8/25 11:52
@Software: PyCharm
@Project: leetcode-python
@File: 231-power-of-two.py
@Version: Python 3.83
"""

from typing import List

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n == (n & -n)

if __name__ == '__main__':
    s = Solution()
    test_list = [
        ([5, False]),
        ([4, True]),
        ([16, True]),
    ]
    for test_index, test_case in enumerate(test_list, start=1):
        *test, result = test_case
        test_result = s.isPowerOfTwo(*test)
        if test_result != result:
            raise ValueError("\n testcase %d error:\n expect: %s \n actually %s" % (test_index, result, test_result))
        print("test_case %d succeed." % test_index)

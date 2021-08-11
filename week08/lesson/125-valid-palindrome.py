#!/usr/bin/env python3
# -*- encoding: utf-8 -*- 
"""
@Author: MiracleWong
@Email: cfwr1991@126.com
@Time: 2021/8/11 22:39
@Software: PyCharm
@Project: leetcode-python
@File: 125-valid-palindrome.py
@Version: Python 3.83
"""
class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [];
        for i in s:
            if i.isalpha() or i.isnumeric():
                t.append(i.lower())
        sT = ''.join(t)
        l, r = 0, len(sT) - 1
        while (l < r):
            if (t[l] != t[r]):
                return False
            l+=1
            r-=1
        return True


if __name__ == '__main__':
    s = Solution()
    # s.isPalindrome("Hello World")
    test_list = [
        ("A man, a plan, a canal: Panama", True),
        ("race a car", False),
        ("0P", False)
    ]
    for test_index, test_case in enumerate(test_list, start=1):
        *test, result = test_case
        test_result = s.isPalindrome(*test)
        if test_result != result:
            raise ValueError("\n testcase %d error:\n expect: %s \n actually %s" % (test_index, result, test_result))
        print("test_case %d succeed." % test_index)

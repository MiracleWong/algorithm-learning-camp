# 解题方法1：利用python 的自带函数 strip() 和 split()
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        last = s.split(" ")[-1]
        return len(last)       
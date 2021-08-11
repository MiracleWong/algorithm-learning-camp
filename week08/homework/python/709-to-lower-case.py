# 解题1：lower() 内置函数
class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()

# 解题2：ASCII码 转换
class Solution:
    def toLowerCase(self, s: str) -> str:

        ansArray = []
        for i in s:
            if 65 <= ord(i) <= 90:
                ansArray.append(chr(ord(i) + 32))
            else:
                ansArray.append(i)
        return ''.join(ansArray)

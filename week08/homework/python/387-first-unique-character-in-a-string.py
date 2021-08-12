# 解法1：采用Python的collections.Counter() 统计各个字母出现的频率
import collections


class Solution:
    def firstUniqChar(self, s: str) -> int:
        frequency = collections.Counter(s)
        # print(frequency)
        for i, ch in enumerate(s):
            # print(str(i) + ':' + ch)
            if frequency[ch] == 1:
                return i
        return -1

# 解法2：自建dict 的 Hash，统计字符出现的次数
class Solution:
    def firstUniqChar(self, s: str) -> int:
        dict1 = {}
        for ch in s:
            dict1[ch] = dict1.get(ch,0) + 1;
        for key in dict1.keys():
            if dict1[key] == 1:
                return s.find(key)
        return -1
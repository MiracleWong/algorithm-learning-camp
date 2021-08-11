# 解题方法1：利用python 的自带函数 strip() 和 split()
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        last = s.split(" ")[-1]
        return len(last)       
    
def lengthOfLastWord(s):
    # 用于计算当前单词长度
    tmp_len=0
    # 记录上一个单词长度
    last_len=0
    # 一趟遍历
    for c in s:
        # 说明当前 word 正在记录中
        if c!=' ': tmp_len+=1
        # 说明此前记录的 非空word 已经结束
        if c==' ' and tmp_len>0:
            last_len = tmp_len
            tmp_len=0
    return last_len if tmp_len==0 else tmp_len
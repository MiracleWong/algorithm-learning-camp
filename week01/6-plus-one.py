class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = [str(i) for i in digits]
        num = int(''.join(digits))
        num += 1
        num = str(num)
        res = []
        for i in num:
            res.append(int(i))
        return res
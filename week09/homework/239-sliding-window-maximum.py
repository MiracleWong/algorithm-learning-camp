import heapq
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # nums = [1, 3, -1, -3, 5, 3, 6, 7]
        # k = 3
        # [3, 3, 5, 5, 6, 7]
        # 使用heapq，采用最大堆 heap (-value, index) （heap默认最小队，-value 转换）

        res, heap = [], []
        for i in range(len(nums)):
            heapq.heappush(heap, (nums[i], i))
            if i + 1 >= k:
                while heap and heap[0][1] < i - ( k - 1 ) :
                    heapq.heappop(heap)
                print(heap[0])
                res.append(heap[0][0])
        return res


if __name__ == '__main__':
    s = Solution()
    test_list = [
        ([1, 3, -1, -3, 5, 3, 6, 7], 3, [3, 3, 5, 5, 6, 7]),
        ([1], 1, [1]),
        ([9,11], 2, [11]),
    ]
    for test_index, test_case in enumerate(test_list, start=1):
        *test, result = test_case
        test_result = s.maxSlidingWindow(*test)
        if test_result != result:
            raise ValueError("\n testcase %d error:\n expect: %s \n actually %s" % (test_index, result, test_result))
        print("test_case %d succeed." % test_index)
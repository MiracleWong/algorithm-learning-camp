import heapq

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # 初始化大顶堆和小顶堆
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        if len(self.max_heap) == len(self.min_heap):
            # 先加到小顶堆，再把小堆顶元素加到大顶堆
            heapq.heappush(self.min_heap, num)
            heapq.heappush(self.max_heap, - heapq.heappop(self.min_heap))
        else:
            # 加到大顶堆，再把大堆顶元素加到小顶堆
            heapq.heappush(self.max_heap, - num)
            heapq.heappush(self.min_heap, - heapq.heappop(self.max_heap))

    def findMedian(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (- self.max_heap[0] + self.min_heap[0]) / 2
        else:
            return - self.max_heap[0]
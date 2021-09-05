import collections


class LRUCache:

    def __init__(self, capacity: int):
        # 结合哈希表与双向链表的数据结构OrderedDict
        self.dict = collections.OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.dict:
            return -1
        # 第一种: pop(key), 放回到最后一个
        # value = self.dict.pop(key)
        # self.dict[key] = value
        # 第二种：OrderedDict 自带 move_to_end 函数
        self.dict.move_to_end(key)
        return self.dict[key]

    def put(self, key: int, value: int) -> None:
        # 如果已经存在，则更新
        if key in self.dict:
            self.dict.move_to_end(key)
        # 不存在，则插入
        self.dict[key] = value
        # 判断容量是否达到上限
        if len(self.dict) > self.capacity:
            self.dict.popitem(last = False)